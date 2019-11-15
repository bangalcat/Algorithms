#include <iostream>

using namespace std;

const int MAX_N = 1000;
const int MAX_D = 10;

int log[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int st[MAX_N+1][MAX_N+1][MAX_D][MAX_D];
int board[MAX_N+1][MAX_N+1] = {0};

int n, m, q; 


void dp_build() {
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + board[i][j];
        }
    }
}

void st_build() {
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            st[i][0][j][0] = dp[i][j];
        }
    }
    for(int j1=1;j1<=MAX_D;++j1) {
        for(int i1=1;i1 + (1<<j1) - 1<= n; ++i1) { // y
            for(int j2=1;j2<=MAX_D;++j2) {
                for(int i2=1;i2 + (1<<j2) -1<= n; ++i2) { // x
                    st[i1][i2][j1][j2] = min(st[i1][j1-1][i2][j2-1], st[i1 + (1<<(j1-1)) + 1][j1-1][i2 + (1<<(j2-1)) + 1][j2-1]);
                }
            }
        }
    }
    log[1] = 0;
    for(int i=2; i<=n;++i) {
        log[i] = log[i/2] + 1;
    }
}

int query(int x1, int y1, int x2, int y2, int len) {
}

int binary_search(int x1, int y1, int x2, int y2) {
    int lo = 0;
    int hi = min(x2 - x1, y2 - y1);
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> board[i][j];
        }
    }
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

    }
    return 0;
}
