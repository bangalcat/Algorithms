#include <iostream>
#include <vector>
#include <map>

using namespace std;

class FenwikTreeR{
    vector<int> tree;
    long long n;
    public:
    FenwikTreeR(long long size) {
        n = size + 1;
        tree.assign(n, 0);
    }
    void add(long long idx, int delta) {
        for(idx;idx<n;idx+=idx&-idx)
            tree[idx] += delta;
    }

    long long range_add(long long l, long long r, int delta) {
        add(l, delta);
        add(r, -delta);
    }

    long long point_query(long long idx){
        long long ret = 0;
        for(idx;idx > 0; idx-=idx&-idx)
            ret += tree[idx];
        return ret;
    }
};

int main()
{
    int n; cin >> n;
    vector<pair<int, int>> query;
    FenwikTreeR left_ft(1e9+1);
    FenwikTreeR right_ft(1e9+1);
    map<long long, int> nmap;
    set<long > data;
    // 압축을 먼저 해야함
    for(int i=0;i<n;++i) {
        char c; long long l, r;
        cin >> c;
        if(c == 'D'){
            cin >> l >> r;
            data.insert(l);
            data.insert(r);
        }else if(c == 'C') {
            int k;
            cin >> k;
        }else{
        }
    }
    int id=1;
    for(auto i : data)
        nmap[i] = id++;
    
    return 0;
}