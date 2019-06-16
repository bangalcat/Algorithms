#include <bits/stdc++.h>

using namespace std;

int dir(char op){
    if(op == 'S') return 0;
    if(op == 'W') return 1;
    if(op == 'N') return 2;
    if(op == 'E') return 3;
}

int dr[4] = {1,0,-1,0}, dc[4] = {0,-1,0,1};

map<vector<int>, vector<int>> root;

vector<int> find(vector<int> u){
    if(root[u] == vector<int>()) return root[u] = u;
    if(root[u] == u) return u;
    auto v = root[u];
    return root[u] = find(v);
}

void merge(vector<int> u, vector<int> v){
    auto nu = find(u), nv = find(v);    
    if(nu == nv) return;
    root[nu] = nv;
}

int main(){
    int T; cin >> T;
    int n, r, c, sr, sc;
    string op;

    for(int t=1; t<= T; ++t){
        root.clear();
        cin >> n >> r >> c >> sr >> sc;
        cin >> op;
        sr--, sc--;
        for(int k=0;k<4;++k){
            merge({sr,sc,k},{sr+dr[k],sc+dc[k],k});
        }
        for(int i=0;i<n;++i){
            int d = dir(op[i]);
            int nr = sr+dr[d], nc = sc+dc[d];
            auto u = find({nr, nc, d});
            sr = u[0], sc = u[1];
            for(int k=0;k<4;++k){
                merge({sr,sc,k},{sr+dr[k],sc+dc[k],k});
            }
            // cout << sr << ' ' << sc << endl;
        }

        cout << "Case #";
        cout << t << ": ";
        cout << sr+1 << ' ' << sc+1;
        cout << '\n';
    }
    return 0;
}