#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

class FenwikTree{
    int n;
    vector<int> tree;
    public:
    FenwikTree(int size) {
        n = size + 1;
        tree.assign(n+1, 0);
    }
    FenwikTree(vector<int> arr){
        n = arr.size() + 1;
        tree.assign(n+1, 0);
        for(int i=0;i<arr.size();++i) {
            update(i, arr[i]);
        }
    }
    void update(int idx, int delta){
        for(idx;idx<n;idx+=(idx&-idx))
            tree[idx] += delta;
    }

    int sum(int idx){
        int ret = 0;
        for(idx;idx > 0; idx-=(idx&-idx))
            ret += tree[idx];
        return ret;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<int> arr(n+1);
    map<int, int> pos;
    for(int i=1;i<=n;++i)
        cin >> arr[i];
    FenwikTree ft(n);
    int q; cin >> q;
    vector<tuple<int,int,int>> queries;
    for(int i=0;i<q;++i) {
        int l, r;
        cin >> l >> r;
        queries.emplace_back(r, l, i);
    }
    sort(queries.begin(), queries.end());
    int curr = 1;
    vector<int> ans(q);
    for(auto &t : queries) {
        int r, l, no;
        tie(r, l, no) = t;
        while(curr <= r){
            if(pos[arr[curr]] > 0)
                ft.update(pos[arr[curr]], -1);
            ft.update(curr, 1);
            pos[arr[curr]] = curr;
            curr++;
        }
        ans[no] = ft.sum(l, r);
    }
    for(auto a: ans)
        cout << a << '\n';
    return 0;
}