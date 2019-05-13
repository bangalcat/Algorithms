/*
    백준 : 이분 그래프
    이분 매칭 판별
    ref. Independent set
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int K; cin >> K;
    while(K--){
        int V, E;
        cin >> V >> E;
        vector<int> adj[20000];
        vector<int> setnum(V,-1);
        for(int i=0;i<E;++i){
            int u, v; cin >> u >> v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        function<bool(int, int)> dfs = [&](int here, int setn){
            setnum[here] = setn;
            for(int there : adj[here]){
                if(setnum[there] == -1 && !dfs(there, 1 - setn))
                    return false;
                else if(setnum[there] == setn)
                    return false;
            }
            return true;
        };
        int c_cnt=0;
        for(int i=0;i<V;++i){
            if(setnum[i] == -1 && !dfs(i, 0)){
                cout << "NO\n";
                break;
            }
            if(i==V-1)
                cout << "YES\n";
        }
    }
    
    return 0;
}