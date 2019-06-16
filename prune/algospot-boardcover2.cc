#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef vector<pair<int,int>> vpii;

int h, w, r, c;
int blockCnt=0;

int covered[11][11]={0};

int best=0;

vector<vpii> rotations;

bool isRange(int hr, int hc, int n, int m){
    return hr >= 0 && hr < n && hc >= 0 && hc < m;
}

vector<string> rotate(const vector<string>& arr){
    vector<string> ret(arr[0].size(), string(arr.size(),' '));
    for(int i=0;i<arr.size();++i){
        for(int j=0;j<arr[0].size();++j)
            ret[j][arr.size()-1-i] = arr[i][j];
    }
    return ret;
}

void generateRotations(vector<string> block){
    rotations.clear();
    rotations.resize(4);
    for(int rot=0;rot<4;++rot){
        int oy = -1, ox = -1;
        for(int i=0;i<block.size();++i){
            for(int j=0;j<block[i].size();++j){
                if(block[i][j] == '#'){
                    if(oy == -1){
                        oy = i, ox = j;
                    }
                    rotations[rot].push_back({i-oy,j-ox});
                }
            }
        }
        block = rotate(block);
    }
    sort(rotations.begin(),rotations.end());
    rotations.erase(unique(rotations.begin(),rotations.end()));
    blockCnt = rotations[0].size();
}

#define fi first
#define se second

bool putBlock(const vpii& block, int hr,int hc, int delta){
    bool ret = true;
    for(auto pp : block) {
        int y = pp.fi;
        int x = pp.se;
        if(isRange(hr+y, hc+x, h, w)) {
            covered[hr+y][hc+x] += delta;
            // if(covered[hr+y][hc+x] < -1 || covered[hr+y][hc+x] > 1) cout << "ALERT\n";
            ret = ret && (covered[hr+y][hc+x]==1);
        }else 
            ret = false;
    }
    return ret;
}

//현재 보드 상태에서, 놓을 수 있는 최대 블록 수
void solve(int cnt){
    int whitespace = 0;
    for(int i=0;i<h;++i) 
        for(int j=0;j<w;++j)
            if(covered[i][j]==0) whitespace++;

    //prunning
    if(cnt + (whitespace / blockCnt) <= best) return;

    int y=-1, x=-1;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(covered[i][j] == 0){
                y = i, x = j;
                break;
            }
        }
        if(y != -1) break;
    }
    if(y ==-1){
        best = max(best, cnt);
        return;
    }
    for (int d = 0; d < rotations.size(); ++d)
    {
        if (putBlock(rotations[d], y, x, 1))
            solve(cnt + 1);
        putBlock(rotations[d], y, x, -1);
    }
    covered[y][x] = 1;
    solve(cnt);
    covered[y][x] = 0;
    return;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> h >> w >> r >> c;
        best = 0;
        vector<string> board(h);
        vector<string> block(r);
        memset(covered, 0x0, sizeof(covered));

        for(int i=0;i<h;++i){
            cin >> board[i];
            for(int j=0;j<w;++j)
                covered[i][j] = (board[i][j] == '#');
        }
        for(int i=0;i<r;++i){
            cin >> block[i];
        }
        generateRotations(block);
        solve(0);
        cout << best << endl;
    }
    return 0;
}