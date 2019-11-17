#include <iostream>
#include <vector>

using namespace std;

class FenwikTree{
    int n;
    vector<vector<int>> tree;
    public:
    FenwikTree(int size) {
        n = size + 1;
        tree.assign(n+1, vector<int>(n+1, 0));
    }

    FenwikTree(vector<vector<int>> arr){
        n = arr.size() + 1;
        tree.assign(n+1, vector<int>(n+1, 0));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j)
                update(i, j, arr[i][j]);
        }
    }

    void update(int x, int y, int delta) {
        for(++x; x < n; x += (x & -x)){
            for(int ty = y+1; ty < n; ty += (ty & -ty))
                tree[x][ty] += delta;
        }
    }
    int sum(int x, int y) {
        int ret=0;
        for(++x;x > 0; x-=(x&-x))
            for(int ty = y+1;ty > 0; ty-=(ty&-ty))
                ret += tree[x][ty];
        return ret;
    }

    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        FenwikTree ft(n);
        vector<vector<int>> arr(n, vector<int>(n,0));
        string op;
        cin >> op;
        while(op != "END"){
            if(op == "SET"){
                int x, y, v;
                cin >> x >> y >> v;
                ft.update(x, y, v - arr[x][y]);
                arr[x][y] = v;
            }else{
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << ft.sum(x1, y1, x2, y2) << '\n';
            }
            cin >> op;
        }
    }
    return 0;
}