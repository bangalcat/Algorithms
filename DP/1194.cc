#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};

bool isRange(int r,int c, int n,int m){
    return r>=0 && r<n && c>=0 && c<m;
}

int main(){
    int n, m; cin >> n >> m;
    vector<string> board(n);
    int dp[50][50][1<<6] = {0};
    queue<pair<pair<int,int>,int>> que;
    int sr=0, sc=0;
    for(int i=0;i<n;++i){
        cin >> board[i];
        for(int j=0;j<m;++j)
            if(board[i][j] == '0')
                sr = i, sc = j;
    }
    memset(dp,-1,sizeof(dp));
    #define f first
    #define s second
    que.push({{sr,sc},0});
    dp[sr][sc][0] = 0;
    while(!que.empty()){
        auto curr = que.front();
        que.pop();
        if(board[curr.f.f][curr.f.s]=='1') {
            cout << dp[curr.f.f][curr.f.s][curr.s] << endl;
            return 0;
        }
        for(int d=0;d<4;++d){
            int nr = curr.f.f + dr[d];
            int nc = curr.f.s + dc[d];
            int np = curr.s;
            if(isRange(nr, nc, n, m) && board[nr][nc] != '#'){
                if(board[nr][nc] >= 'A' && board[nr][nc] <= 'F' && !(np & (1<<(board[nr][nc]-'A'))))
                    continue;
                if(board[nr][nc] >= 'a' && board[nr][nc] <= 'f') 
                    np = np | (1<<(board[nr][nc]-'a'));
                if(dp[nr][nc][np]==-1 || dp[nr][nc][np] > dp[curr.f.f][curr.f.s][curr.s]+1){
                    dp[nr][nc][np] = dp[curr.f.f][curr.f.s][curr.s] + 1;
                    que.push({{nr,nc},np});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}