#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_V = 54;
int V;

int toInt(char s){
    return (s>='a')?(s-'a'+26):(s-'A');
}

vector<int> adj[MAX_V];

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int network_flow(int src, int sink){
    memset(flow, 0x0, sizeof(flow));
    int totFlow = 0;
    while(true){
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[src] = src;
        q.push(src);
        while(!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for(auto there : adj[here]){
                if(capacity[here][there] - flow[here][there] > 0 && parent[there]==-1)
                {
                    q.push(there);
                    parent[there] = here;
                    if(there == sink) break;
                }
            }
        }
        if(parent[sink] == -1) break;
        int amt = INF;
        // get available flow amount
        for(int p = sink; p != src; p = parent[p])
            amt = min(capacity[parent[p]][p] - flow[parent[p]][p], amt);
        // go flow
        for (int p = sink; p != src; p = parent[p])
        {
            flow[parent[p]][p] += amt;
            flow[p][parent[p]] -= amt;
        }
        totFlow += amt;
    }
    return totFlow;
}


int main()
{
    int N; cin >> N;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(capacity,0,sizeof(capacity));
    for(int i=0;i<N;++i){
        char a, b; int c;
        cin >> a >> b >> c;
        int u = toInt(a), v = toInt(b);
        capacity[u][v] = capacity[v][u] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    V = 52;
    cout << network_flow(toInt('A'), toInt('Z'));
    return 0;
}