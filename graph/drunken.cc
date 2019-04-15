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
    vector<vector<int>> maxLatency(V, vector<int>(V,INF));
    for(int i=0;i<V;++i)
        cin >> latency[i];
    for(int i=0;i<E;++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
        maxLatency[a-1][b-1] = maxLatency[b-1][a-1] = c;
    }
    for(int i=0;i<V;++i)
        maxLatency[i][i] = 0;
    vector<pair<int,int>> order;
    for(int i=0;i<V;++i)
        order.push_back({latency[i], i});
    sort(order.begin(),order.end());
    //floyd
    for(int k=0;k<V;++k)
    {
        int w = order[k].second;
        for(int i=0; i<V; ++i)
        {
            if(adj[i][w] != INF)
            for(int j=0; j<V; ++j)
            {
                adj[i][j] = min(adj[i][w] + adj[w][j], adj[i][j]);
                maxLatency[i][j] = min(adj[i][w] + latency[w] + adj[w][j], maxLatency[i][j]);
            }
        }
    }
    // test case
    int tc; cin >> tc;
    int src, dest;
    while(tc--)
    {
        cin >> src >> dest;
        cout << maxLatency[src-1][dest-1] << '\n';
    }
    return 0;
}
