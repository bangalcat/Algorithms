#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//게임판 정보

int boardH, boardW; //board Height(세로), board Width(가로)
vector<string> board;
//블록의 크기
int blockSize;
int covered[10][10];
vector<vector<pair<int, int>>> rotations; //이차원 벡터
vector<string> rotate(const vector<string> &arr)
{
    vector<string> result(arr[0].size(), string(arr.size(), ' ')); //가로와 세로가 뒤바뀐 vector 생성
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[0].size(); j++)
            result[j][arr.size() - i - 1] = arr[i][j]; //90도 회전
    return result;
}

void generateRotations(vector<string> block)
{
    rotations.clear();
    rotations.resize(4); //네가지 회전
    for (int rot = 0; rot < 4; rot++)
    {
        int originY = -1, originX = -1;
        for (int i = 0; i < block.size(); i++)
            for (int j = 0; j < block[i].size(); j++)
                if (block[i][j] == '#')
                {
                    if (originY == -1)
                    {
                        originY = i;
                        originX = j;
                    }
                    rotations[rot].push_back(make_pair(i - originY, j - originX));
                }
        block = rotate(block);
    }

    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();
}

bool isRange(int r,int c,int h, int w){
    return r >= 0 && r < h && c >= 0 && c < w;
}

bool set(int y, int x, const vector<pair<int, int>> &block, int delta)
{
    bool result = true;
    for (auto& pp : block)
    {
        //범위 내에 있다면
        if (isRange(pp.first + y,pp.second + x, boardH, boardW))
        {
            covered[y + pp.first][x + pp.second] += delta;
            result = result && (covered[y + pp.first][x + pp.second] == 1);
        }
        else
            result = false;
    }
    return result;
}

int best; //지금까지 찾은 최적해

int blockPrune(int placed) //가지치기
{
    int cnt = 0;
    for (int i = 0; i < boardH; i++)
        for (int j = 0; j < boardW; j++)
            cnt += !(covered[i][j]) ? 1 : 0;
    return ((cnt / blockSize) + placed <= best);
}

void search(int placed) //placed:지금까지 놓은 블록의 수
{
    if (blockPrune(placed)) //가지치기
        return;
    int y = -1, x = -1;
    for (int i = 0; i < boardH; i++)
    {
        for (int j = 0; j < boardW; j++)
        {
            if (covered[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
        }

        if (y != -1)
            break;
    }

    //기저 사례:게임판의 모든 칸을 처리한 경우
    if (y == -1)
    {
        best = max(best, placed);
        return;
    }

    //이 칸을 덮는다
    for (int i = 0; i < rotations.size(); i++)
    {
        if (set(y, x, rotations[i], 1))
            search(placed + 1);
        //다시 없앤다
        set(y, x, rotations[i], -1);
    }

    //이 칸을 덮지 않고 막아둔다
    covered[y][x] = 1;
    search(placed);
    covered[y][x] = 0;
}

int solve(void)
{
    best = 0;
    //covered 배열 초기화
    for (int i = 0; i < boardH; i++)
        for (int j = 0; j < boardW; j++)
            covered[i][j] = board[i][j] == '#';
    search(0);
    return best;
}

int main(void)
{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        board.clear();
        vector<string> block;
        int blockH, blockW; //블록의 세로, 가로 크기

        cin >> boardH >> boardW >> blockH >> blockW;
        for (int j = 0; j < boardH; j++) {
            string temp;
            cin >> temp;
            board.push_back(temp);
        }

        for (int j = 0; j < blockH; j++)
        {
            string temp;
            cin >> temp;
            block.push_back(temp);
        }

        generateRotations(block);
        cout << solve() << endl;
    }

    return 0;
}