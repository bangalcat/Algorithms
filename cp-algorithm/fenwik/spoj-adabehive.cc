#include <iostream>
#include <vector>

using namespace std;

class FenwikTree{
    int n, m;
    vector<vector<long long>> tree;
    public:
    FenwikTree(vector<vector<int>> arr){
        n = arr.size() + 1;
        m = arr[0].size() + 1;
        tree.assign(n+1, vector<long long>(m+1, 0));
        for(int i=1;i<n;++i) {
            for(int j=1;j<m;++j)
                update(i, j, arr[i-1][j-1]);
        }
    }

    void update(int x, int y, int delta) {
        for(x; x < n; x += (x & -x)){
            for(int ty = y; ty < m; ty += (ty & -ty))
                tree[x][ty] += delta;
        }
    }
    long long sum(int x, int y) {
        long long ret=0;
        for(x;x > 0; x-=(x&-x))
            for(int ty = y;ty > 0; ty -= (ty & -ty))
                ret += tree[x][ty];
        return ret;
    }

    long long sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> arr[i][j];
    FenwikTree ft(arr);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, d;
            cin >> x >> y >> d;
            ft.update(x, y, d);
        }else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << ft.sum(x1, y1, x2, y2) << '\n';
        }

    }
    return 0;
}