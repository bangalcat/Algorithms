#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for(int i=0;i<n;++i) {
        cin >> board[i];
    }
    int ans = 1;
    int min_l = min(n, m);
    for(int r=0;r<n-1;++r) {
        for(int c=0;c<m-1;++c) {
            // 3 꼭지점 확인
            for(int k=1;k<min_l;++k) {
                int x1 = c+k, y1 = r;
                int x2 = c, y2 = r+k;
                int x3 = x1, y3 = y2;
                if (x1 < m && y2 < n && board[r][c] == board[y1][x1] &&
                    board[r][c] == board[y2][x2] && board[r][c] == board[y3][x3])
                {
                    ans = max(ans, (k+1) * (k+1));
                    // cout << x3 << ' ' << y3 << '\n';
                }
            }
        }
    }
    cout << ans;
    return 0;
}