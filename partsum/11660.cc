#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> psum(n+1, vector<int>(n+1,0));

    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            int a;
            cin >> a;
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + a;
        }
    }

    for(int i=0;i<m;++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << psum[x2][y2] - psum[x2][y1] - psum[x1][y2] + psum[x1][y1] << '\n';
    }

    return 0;
}