#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[3001];
    for(int i=0;i<m;++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<n;++i)
        adj[i+1].push_back(0);
    auto isFC = [&](int closeBarn){
        adj[closeBarn].clear();
        vector<bool> visited(n+1,false);
        visited[0] = true;
        function<void(int)> dfs = [&dfs, &adj, &visited, n, closeBarn](int here){
            visited[here] = true;
            for(auto& there : adj[here]) {
                if(there == closeBarn) {
                    there = 0;
                    continue;
                }
                if(!visited[there])
                    dfs(there);
            }
        };
        for(int i=1;i<=n;++i)
            if(!adj[i].empty()){
                dfs(i);
                break;
            }
        for(int i=1;i<=n;++i)
            if(!visited[i] && !adj[i].empty())
                return false;
        return true;
    };
    cout << (isFC(0)?"YES":"NO") << endl;
    for(int i=0;i<n;++i) {
        int cb; cin >> cb;
        if(i==n-1) break;
        cout << (isFC(cb)?"YES":"NO") << endl;
    }
    return 0;
}