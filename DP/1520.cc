/*
    내리막길 문제
    어려웠던 부분 : dp[r][c]가 0이 되는 부분이 존재
    싸이클을 이루는 부분이 존재 - 무한루프에 빠짐
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;
typedef vector<vector<int>> VVI;
typedef vector<vector<bool>> VVB;
typedef vector<int> VI;
typedef vector<bool> VB;
int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};

class Solver{
    int m,n; 
    VVI map;
    VVI dp;
public:
    Solver(int m, int n, VVI& map):m(m),n(n),map(map){
        dp.assign(m,VI(n,-1));
    }
    int dfs(int r, int c){
        if(r == m-1 && c == n-1){
            return 1;
        }
        if(dp[r][c]>=0) return dp[r][c];
        dp[r][c] = 0;
        for(int d=0;d<4;d++){
            int nr = r+dr[d];
            int nc = c+dc[d];
            if(nr < 0 || nr >=m || nc < 0 || nc >= n) continue;
            if(map[r][c] > map[nr][nc])
                dp[r][c] += dfs(nr,nc);
        }
        
        return dp[r][c];
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n; cin >> m >> n;
    VVI map(m,VI(n));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n; j++){
            cin >> map[i][j];
        }
    }
    Solver solver(m,n,map);
    cout << solver.dfs(0,0);
    return 0;
}