#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999999;

int V, E;

int main(void)
{
    cin >> V >> E;
    vector<int> latency(V);
    vector<vector<int>> adj(V,vector<int>(V,INF));
    vector<vector<int>> via(V, vector<int>(V,-1));
    vector<vector<int>> maxLatency(V, vector<int>(V,0));
    for(int i=0;i<V;++i)
        cin >> latency[i];
    for(int i=0;i<E;++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }
    //floyd
    for(int k=0;k<V;++k)
    {
        for(int i=0; i<V; ++i)
        {
            if(adj[i][k] != INF)
            for(int j=0; j<V; ++j)
            {
                int currLatency = maxLatency[i][j];
                int ikLatency = maxLatency[i][k];
                int kjLatency = maxLatency[k][j];
                if(adj[i][j] + currLatency > adj[i][k] + adj[k][j] + max({ikLatency, kjLatency, latency[k]}))
                {
                    maxLatency[i][j] = max({ikLatency, kjLatency, latency[k]});
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    // test case
    int tc; cin >> tc;
    int src, dest;
    while(tc--)
    {
        cin >> src >> dest;
        cout << adj[src-1][dest-1] + maxLatency[src-1][dest-1] << '\n';
    }
    return 0;
}
