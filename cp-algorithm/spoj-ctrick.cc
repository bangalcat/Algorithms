#include <iostream>
#include <vector>
#include <map>

using namespace std;

class FT {
    int n;
    vector<int> tree;

    public:
    FT(const vector<int>& arr, int size){
        n = size;
        tree.assign(n+1, 0);
        for(int i=0;i<n;++i)
            update(i, arr[i]);
    }

    void update(int idx, int d) {
        for(++idx; idx <= n;idx += (idx & -idx))
            tree[idx] += d;
    }

    int sum(int idx) {
        int ret = 0;
        for(++idx; idx > 0; idx -= (idx & -idx))
            ret += tree[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    ~FT() {
        tree.clear();
    }
};

int main() 
{
    int T; cin >> T;
    map<int,vector<int>> ans_map;
    vector<int> arr;
    while(T--) {
        int n; cin >> n;
        arr.assign(n, 1);
        FT ft(arr, n);
        int prev = -1;
        for(int i=1; i<= n; ++i) {
            int move = (i + ft.sum(prev-1)) % (n - i + 1);
            // cout << "move : " << move << endl;
            int lo = 0, hi = n;
            while(lo < hi) {
                int mid = (lo + hi) / 2;
                if(ft.sum(mid) <= move)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            // cout << "hi : " << hi << endl;
            arr[lo] = i;
            ft.update(lo, -1);
            prev = lo;
        }
        for(int i=0;i<n;++i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    return 0;
}