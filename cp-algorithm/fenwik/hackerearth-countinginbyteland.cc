#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<vector<long long>>> vvvl;

class FenwikTree3d{
    int n;
    vvvl tree;
    public:
    FenwikTree3d(int size) {
        n = size + 1;
        tree.assign(n, vector<vector<long long>>(n, vector<long long>(n, 0)));
    }
    void update(int x, int y, int z, int delta) {
        for(int i=x+1; i<n; i+=i&-i)
            for(int j=y+1; j<n; j+=j&-j)
                for(int k=z+1; k<n; k+=k&-k)
                    tree[i][j][k] += delta;
    }
    long long sum(int x, int y, int z) {
        long long ret=0;
        for(int i=x+1; i>0; i-=i&-i)
            for(int j=y+1; j>0; j-=j&-j)
                for(int k=z+1; k>0; k-=k&-k)
                    ret += tree[i][j][k];
        return ret;
    }

    long long sum(int x1, int y1, int z1, int x2, int y2, int z2){
        x1--,y1--,z1--;
        return sum(x2,y2,z2) - sum(x2,y2,z1) - sum(x2,y1,z2) - sum(x1,y2,z2) \
                + sum(x1,y1,z2) + sum(x1,y2,z1) + sum(x2,y1,z1) - sum(x1,y1,z1);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    FenwikTree3d ft(n+1);
    long long tot = 0;
    vvvl hotel(n+1, vector<vector<long long>>(n+1, vector<long long>(n+1, 0)));
    for(int i=0;i<q;++i) {
        int op; cin >> op;
        if(op == 1) {
            int x, y, z, val;
            cin >> x >> y >> z >> val;
            // val = val - hotel[x][y][z];
            ft.update(x, y, z, val);
            // hotel[x][y][z] += val;
            tot += val;
            // cout << "debug : " << ft.sum(x, y, z) << '\n';
        }else{
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << tot - ft.sum(x1, y1, z1, x2, y2, z2) << '\n';
        }
    }
    return 0;
}