#include <bits/stdc++.h>

using namespace std;

vector<int> A[2], B;
vector<vector<int>> adj;
vector<bool> visited;
int n, m, k;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto v : adj[a]){
        if(B[v] == -1 || !visited[B[v]] && dfs(B[v])){
            A[k][a] = v;
            B[v] = a;
            return true;
        }
    }
    return false;
}

int bipartite(){
    A[0] = A[1] = vector<int>(n,-1);
    B = vector<int>(m,-1);
    int size= 0;
    for (k = 0; k < 2; ++k){
        for (int start = 0; start < n; ++start)
        {
            visited = vector<bool>(n, false);
            size += dfs(start);
        }
    }
    return size;
}

int main(){
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        for(int i=0;i<n;++i){
            int ct; cin >> ct;
            for(int j=0;j<ct;++j){
                int b; cin >> b;
                adj[i].push_back(b-1);
            }
        }
        cout << bipartite() << '\n';
    
    return 0;
}