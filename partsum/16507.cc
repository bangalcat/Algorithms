#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> psum(n+1, vector<int>(m+1,0));

    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            int a;
            cin >> a;
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + a;
        }
    }
    for(int i=0;i<q; ++i){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int div = (r2 - r1 + 1) * (c2 - c1 + 1);
        r1--, c1--;
        int up = psum[r2][c2] - psum[r2][c1] - psum[r1][c2] + psum[r1][c1];
        cout << up/div << '\n';
    }
    
    return 0;
}