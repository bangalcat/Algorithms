#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Query{
    int r, l;
    bool operator <(const Query& rhs) const {
        return r == rhs.r ? l < rhs.l : r < rhs.r;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n);
    vector<long long> psum(n+1,0);
    for(int i=0;i<n;++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;++i)
        psum[i+1] = psum[i] + arr[i];
    int q; cin >> q;
    for(int i=0;i<q;++i) {
        int a, b; cin >> a >> b;
        int l = upper_bound(arr.begin(), arr.end(), a-1) - arr.begin();
        int r = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
        long long ans = psum[r] - psum[l];
        cout << ans << '\n';
    }
    
    return 0;
}