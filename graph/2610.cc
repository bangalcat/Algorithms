// 백준 : 회의 준비
// 
#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

vector<vector<int>> adj;
const int INF = 987654321;
const int MAX_V = 101;

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n,vector<int>(n,INF));
    //disjoint-set init
    vector<int> root(MAX_V, -1);
    for(int i=0;i<n;++i)
        root[i] = i;

    function<int(int)> find = [&](int u) {
        if (root[u] == u)
            return u;
        return find(root[u]);
    };
    auto merge = [&](int u, int v) {
        u = find(u), v = find(v);
        if (u == v)
            return u;
        root[v] = u;
        return u;
    };
    //input
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
        merge(a, b);
    }
    // floyd
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    vector<bool> confirmed(n,0);
    set<pair<int,int>> cands;

    for (int i = 0; i < n; ++i) {
        int c_time=0;
        for (int j = 0; j < n; ++j) {
            if (i != j && adj[i][j] < INF) {
                c_time = max(c_time,adj[i][j]);
            }
        }
        cands.insert({c_time, i});
    }
    set<int> ans;
    for(auto pr : cands){
        int c = pr.second;
        if(confirmed[find(c)]) continue;
        ans.insert(c);
        confirmed[find(c)] = true;
    }
    cout << ans.size() << endl;
    for(auto a : ans)
        cout << a+1 << endl;

    return 0;
}