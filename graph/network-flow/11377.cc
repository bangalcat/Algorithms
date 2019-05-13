/*
    백준 : 열혈강호 3
    이분 매칭
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> A[2], B;
vector<vector<int>> adj;
vector<bool> visited;
int n, m, k;

bool dfs(int a, int t){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto v : adj[a]){
        if(B[v] == -1 || !visited[B[v]] && dfs(B[v], t)){
            A[t][a] = v;
            B[v] = a;
            return true;
        }
    }
    return false;
}

int bipartite(){
    A[0] = A[1] = vector<int>(n,-1);
    B = vector<int>(m,-1);
    int size[2] = {0};
    for (int t = 0; t < 2; ++t){
        for (int start = 0; start < n; ++start)
        {
            visited = vector<bool>(n, false);
            size[t] += dfs(start, t);
            if(size[1] >= k) break;
        }
    }
    return size[0] + size[1];
}

int main(){
        cin >> n >> m >> k;
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