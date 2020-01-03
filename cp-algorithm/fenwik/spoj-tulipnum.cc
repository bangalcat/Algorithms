#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T; cin >> T;
    for(int t=0;t<T;++t){
        int n, q; cin >> n >> q;
        vector<int> arr(n+1);
        vector<int> presum(1e5+1, 0);
        int id = 0;
        long long prev = -1;
        for(int i=1;i<=n;++i) {
            long long x;
            cin >> x;
            if(x != prev){
                presum[++id] = 1;
            }
            arr[i] = id;
            prev = x;
        }
        for(int i=1;i <= id; ++i){
            presum[i] += presum[i-1];
        }
        cout << "Case " << t+1 << ":\n";
        for(int i=0;i<q;++i) {
            int l, r; cin >> l >> r;
            cout << presum[arr[r]] - presum[arr[l]-1] << '\n';
        }
    }
    return 0;
}