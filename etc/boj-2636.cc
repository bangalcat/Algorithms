#include <bits/stdc++.h>

// 백준 : 치즈

using namespace std;

int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
int board[101][101];
bool visited[101][101];
int h, w;

bool isRange(int r, int c, int h, int w) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

void dfs(int r, int c) {
    if(board[r][c] == 3) board[r][c] = 2;
    for(int d=0;d<4;++d) {
        if(isRange(r+dr[d], c+dc[d], h, w) && board[r+dr[d]][c+dc[d]] == 0){
            board[r+dr[d]][c+dc[d]] = 2;
            dfs(r+dr[d], dc[d] + c);
        }
    }
}

int main(){
    cin >> h >> w;
    int cnt = 0, step = 0;
    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j){
            cin >> board[i][j];
            if(board[i][j] == 1) cnt++;
            if(i==0 || i==h-1 || j==0 || j==w-1) board[i][j] = 2;
        }
    }
    int ans = 0;
    while(cnt) {
        step++;
        for(int i=0;i<h;++i) {
            for(int j=0;j<w;++j) {
                if(board[i][j] >= 2)
                    dfs(i,j);
            }
        }
        int rmcnt = 0;
        for(int i=0;i<h;++i) {
            for(int j=0;j<w;++j) {
                if(board[i][j] == 1){
                    for(int d=0;d<4;++d) {
                        if(board[i+dr[d]][j+dc[d]] == 2){
                            board[i][j] = 3;
                            rmcnt++;
                            break;
                        }
                    }
                }
            }
        }
        if(rmcnt == cnt) ans = cnt;
        cnt -= rmcnt;
    }
    cout << step << endl;
    cout << ans;
    return 0;
}