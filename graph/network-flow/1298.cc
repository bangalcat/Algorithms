/*
    백준 : 노트북의 주인을 찾아서
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;
vector<vector<int>> adj;
vector<bool> visited;
int n, m;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto v : adj[a]){
        if(B[v] == -1 || !visited[B[v]] && dfs(B[v])){
            A[a] = v;
            B[v] = a;
            return true;
        }
    }
    return false;
}

int bipartite(){
    A = vector<int>(n,-1);
    B = vector<int>(n,-1);
    int size= 0;
    for (int start = 0; start < n; ++start)
    {
        visited = vector<bool>(n, false);
        size += dfs(start);
    }
    return size;
}

int main(){
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        for(int i=0;i<m;++i){
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
        }
        cout << (m>0?bipartite():0) << '\n';
    
    return 0;
}