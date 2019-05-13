
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N=10, MAX_M=10;
//count of vertice of A and B
int n, m;
// adj[i][j] is Ai and Bj is connected?
bool adj[MAX_N][MAX_M];
vector<int> aMatch, bMatch;
//dfs()
vector<bool> visited;
// find path which a to b in unmatched B
bool dfs(int a){
    if (visited[a]) return false;
    visited[a] = true;
    for(int b=0;b<m;++b){
        if(adj[a][b])
            if(bMatch[b] == -1 || dfs(bMatch[b])){
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
    }
    return false;
}
// procedure aMatch, bMatch and return max matching
int bipartiteMatch(){
    aMatch = vector<int>(n,-1);
    bMatch = vector<int>(m,-1);
    int size = 0;
    for(int start = 0; start < n; ++start){
        visited = vector<bool>(n, false);
        if(dfs(start))
            ++size;
    }
    return size;
}
int main()
{
    return 0;
}