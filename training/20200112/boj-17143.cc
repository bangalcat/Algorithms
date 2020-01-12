#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dr[4] = {-1,1,0,0}, dc[4] = {0,0,1,-1};
int R, C, M;

struct Shark {
    int r, c, s, d, z;
};

map<int, Shark*> sharks;

int move(Shark* sk, int dir, int pos, int n){
    int npos = pos + sk->s * dir + (n-1) * 2 * sk->s;
    npos %= (n-1)*2;
    if(npos >= n){
        npos = (n - 1) * 2 - npos;
        sk->d = sk->d < 2 ? 1 - sk->d : (4 - sk->d) + 1;
    }
    return npos;
}

int main()
{
    cin >> R >> C >> M;
    // 낚시터 board, new board, 상어들 리스트
    vector<vector<int>> board(R, vector<int>(C, 0));
    for(int i=0;i<M;++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        sharks[i+1] = new Shark{r-1, c-1, s, d-1, z};
        board[r-1][c-1] = i+1;
    }
    int ans = 0;
    for(int j=0;j<C;++j) {
        // 1. 낚시왕 이동
        // 2. 해당 열 가장 먼저 발견되는 물고기 제거
        for(int i=0;i<R;++i) {
            if(board[i][j] != 0){
                // cout << board[i][j] << ' ' << sharks[board[i][j]]->z << '\n';
                ans += sharks[board[i][j]]->z;
                sharks.erase(board[i][j]);
                board[i][j] = 0;
                break;
            }
        }
        vector<vector<int>> newBoard(R, vector<int>(C, 0));
        // 3. 물고기들 이동(이동하면서 겹치는 더 작은 상어 제거)
        vector<int> rmcands;
        for(auto sk = sharks.begin();sk != sharks.end();sk++){
            int num = sk->first;
            auto k = sk->second;
            int nr = move(k, dr[k->d], k->r, R);
            int nc = move(k, dc[k->d], k->c, C);
            k->r = nr;
            k->c = nc;
            if(newBoard[nr][nc] != 0) {
                if(sharks[newBoard[nr][nc]]->z < k->z){
                    rmcands.push_back(newBoard[nr][nc]);
                    newBoard[nr][nc] = num;
                }else {
                    rmcands.push_back(num);
                }
            }else
                newBoard[nr][nc] = num;
        }
        for(auto id : rmcands)
            sharks.erase(id);
        board = newBoard;
    }
    cout << ans;
    return 0;
}