#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    while(T--) {
        int k, n; cin >> k >> n;
        vector<int> weights[4];
        for(int i=0;i<4;++i){
            for(int _=0;_<n;++_){
                int a; cin >> a;
                weights[i].push_back(a);
            }
        }
        vector<int> prod[2];
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                prod[0].push_back(weights[0][i] + weights[1][j]);
                prod[1].push_back(weights[2][i] + weights[3][j]);
            }
        }
        sort(prod[1].begin(),prod[1].end());

        int ret = prod[0].front() + prod[1].front();
        for(auto stand : prod[0]){
            int lo = -1;
            int hi = prod[1].size();
            while(lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                // cout << lo << ' ' << mid << ' ' << hi <<' ' << stand << ' ' <<prod[1][mid] <<'\n';
                if(stand + prod[1][mid] < k) {
                    if(abs(stand + prod[1][mid] - k) <= abs(ret - k)){
                        ret = stand + prod[1][mid];
                    }
                    lo = mid;
                } else {
                    if(abs(stand + prod[1][mid] - k) < abs(ret - k)) {
                        ret = stand + prod[1][mid];
                    }
                    hi = mid;
                }
            }
            if(ret == k) break;
        }
        cout << ret << endl;
    }
    return 0;
}