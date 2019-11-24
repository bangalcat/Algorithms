#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class FenwikTree {
    vector<int> tree;
    int n;
    public:
    FenwikTree(int size) {
        n = size + 1;
        tree.assign(n, 0);
    }
    void update(int idx, int d) {
        for(idx;idx<n;idx+=idx&-idx)
            tree[idx] += d;
    }
    int sum(int idx) {
        int ret=0;
        for(idx;idx>0;idx-=idx&-idx)
            ret += tree[idx];
        return ret;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T; cin >> T;
    for(int t=0;t<T;++t){
        int n, q; cin >> n >> q;
        vector<int> arr(n+1);
        for(int i=1;i<=n;++i)
            cin >> arr[i];
        FenwikTree ft(n);
        vector<pair<pair<int, int>,int>> quries;
        for(int i=0;i<q;++i) {
            int l, r; cin >> l >> r;
            quries.push_back({{r, l},i});
        }
        sort(quries.begin(), quries.end());
        int curr = 1;
        map<int, int> pos;
        vector<int> ans(q);
        for(int i=0;i<q;++i) {
            int no = quries[i].second;
            int l = quries[i].first.second;
            int r = quries[i].first.first;
            while(curr <= r){
                if(pos[arr[curr]] > 0)
                    ft.update(pos[arr[curr]], -1);
                ft.update(curr, 1);
                pos[arr[curr]] = curr;
                curr++;
            }
            ans[no] = ft.sum(l, r);
        }
        cout << "Case " << t+1 << ":\n";
        for(auto a : ans)
            cout << a << '\n';
    }
    return 0;
}