#include <iostream>
#include <vector>

using namespace std;

int n; 
int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};

int dfs(vector<string>& board, vector<vector<int>>& check, int r, int c, char prev) {
    if(r < 0 || r >= n || c < 0 || c >= n || check[r][c])
        return 0;
    if(board[r][c] != prev){
        return 1;
    }
    check[r][c] = 1;
    for(int d=0;d<4;++d)
        dfs(board, check, r+dr[d], c+dc[d], board[r][c]);
    return 1;
}

int main()
{
    cin >> n;
    vector<string> board(n);
    for(int i=0;i<n;++i)
        cin >> board[i];
    vector<vector<int>> check(n, vector<int>(n, 0));

    int n_cnt = 0, s_cnt = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            n_cnt += dfs(board, check, i, j, board[i][j]);
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    check = vector<vector<int>>(n, vector<int>(n, 0));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            s_cnt += dfs(board, check, i, j, board[i][j]);
    cout << n_cnt << ' ' << s_cnt;
    return 0;
}