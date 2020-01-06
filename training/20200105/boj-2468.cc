#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};
int n;
int arr[101][101];

int dfs(int check[101][101], int r,int c, int h) {
    if(r >= n || r < 0 || c >= n || c < 0) return 0;
    if(arr[r][c] <= h) return 0;
    if(check[r][c])
        return 0;
    check[r][c] = 1;
    for(int d=0;d<4;++d)
        dfs(check, r+dr[d], c+dc[d], h);
    return 1;
}

int main()
{
    cin >> n;
    int maxheight = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cin >> arr[i][j];
            maxheight = max(maxheight, arr[i][j]);
        }
    }
    int ans = 0;
    for(int h=0;h<maxheight;++h) {
        //dfs
        int check[101][101] = {0};
        int cnt = 0;
        for(int i=0;i<n;++i) { 
            for(int j=0;j<n;++j) {
                if(!check[i][j])
                    cnt += dfs(check, i, j, h);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}