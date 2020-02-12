#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<pair<long long, long long>> pos;
        vector<long long> ys(n, 0);
        for(int i=0;i<n;++i) {
            long long x, y; 
            cin >> x >> y;
            pos.push_back({x, -y});
            ys[i] = -y;
        }
        sort(ys.begin(), ys.end());
        sort(pos.begin(), pos.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        map<long long, int> mapper;
        int ct = 0;
        for(auto& y : ys){
            mapper[-y] = ct;
            ct += 1;
        }
        vector<long long> tree(ct + 1, 0);
        auto add = [&](int idx) {
            for(++idx; idx <= ct; idx+=idx&-idx) {
                tree[idx] += 1;
            }
        };
        auto sum = [&](int idx) {
            long long ret = 0;
            for(++idx; idx > 0; idx-=idx&-idx){
                ret += tree[idx];
            }
            return ret;
        };
        long long ans = 0;
        for(int i=0; i<n; ++i) {
            ans += sum(mapper[-pos[i].second]);
            add(mapper[-pos[i].second]);
        }
        cout << ans << '\n';
    }
    return 0;
}