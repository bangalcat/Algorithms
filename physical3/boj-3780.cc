#include <bits/stdc++.h>

/*
    using Disjoint-set
 */

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> root(n+1);
        vector<int> dist(n+1,0);

        //init
        for(int i=1;i<n+1;++i)
            root[i] = i;
        function<int(int)> find = [&dist, &root, &find](int u) {
            if(root[u] == u) return u;
            else {
                int r = find(root[u]);
                dist[u] += dist[root[u]];
                return root[u] = r;
            }
        };
        auto merge = [&dist, &root, &find](int u, int v) {
            dist[u] += abs(u - v) % 1000;
            root[u] = v;
        };
        while(true) {
            char op;
            cin >> op;
            if(op == 'O') break;
            else if(op =='I') {
                int a, b;
                //connect a to b
                // a is always root
                cin >> a >> b;
                merge(a, b);
            }else { // op = E
                int u; cin >> u;
                find(u);
                cout << dist[u] << '\n';
            }
        }

    }
    return 0;
}