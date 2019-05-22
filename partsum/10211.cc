#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> psum(n+1,0);
        int maxsum=-99999999, last = 0; 
        for (int i=0;i<n;++i){
            int a; cin >> a;
            psum[i+1] = psum[i] + a;
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n+1;++j){
                maxsum = max(maxsum,psum[j] - psum[i]);
            }
        }

        cout << maxsum << '\n';
    }
    return 0;
}