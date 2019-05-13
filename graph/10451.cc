/*
    백준 : 순열 사이클
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int adj[1001];
        for (int i=1; i <= n; ++i)
        {
            int a; cin >> a;
            adj[i] = a;
        }
        vector<bool> visited(1001,false);
        function<bool(int)> dfs = [&](int here){
            if(visited[adj[here]]) return true;
            visited[adj[here]] = true;
            return dfs(adj[here]);
        };
        int ans=0;
        for (int i=1; i <= n; ++i){
            if(!visited[i])
                ans += dfs(i);
        }
        cout << ans << endl;
    }

    return 0;
}