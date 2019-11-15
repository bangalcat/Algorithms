#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_D = 18;
const int MAX_N = 1e5+1;
const int INF = 1e9+10;

int st[MAX_N+1][MAX_D+1];
int n, k;
int log[MAX_N];
void build() {
    for(int j=1;j<MAX_D;++j) {
        for(int i=0;i + (1<<j) <= n; ++i) {
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
    log[1] = 0;
    for(int i=2; i<=n;++i) {
        log[i] = log[i/2] + 1;
    }
}

int query(int l, int r) {
    int kk = log[r - l + 1];
    return min(st[l][kk], st[r - (1<<kk)+1][kk]);
}

int solve() {
    int ret = -INF;
    for(int m = 0; m < n-1; ++m) {
        ret = max(ret, max(query(0, m), query(m+1, n-1)));
    }
    return ret;
}

int main()
{
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
        st[i][0] = arr[i];
    }
    int ans = 0;
    if(k == 1){
        ans = *min_element(arr.begin(), arr.end());
    }else if(k == 2){
        build();
        ans = solve();
    }else{
        ans = *max_element(arr.begin(), arr.end()); 
    }
    cout << ans << endl;
    return 0;
}