#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e12+1;

void setReachable(vector<vector<pair<int,int>>>& adj, vector<vector<int>>& reachable)
{
    int n = adj.size();
    for(int i=0;i<n;++i)
        reachable[i][i] = 1;

    for(int k=0;k<n;++k)
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            reachable[i][j] |= (reachable[i][k] & reachable[k][j]);
}

int main()
{
    auto f = freopen("test.in","r",stdin);
    int N, S, E, M;
    cin >> N >> S >> E >> M;
    vector<vector<pair<int,int>>> adj(N);
    vector<vector<int>> reachable(N,vector<int>(N,0));
    vector<int> income(N);
    for(int i=0;i<M;++i)
    {
        int a, b, c;
        cin >> a>> b >> c;
        adj[a].push_back({b,c});
        reachable[a][b] = 1;
    }
    for(int i=0;i<N;++i)
        cin >> income[i];
    setReachable(adj, reachable);
    //how about bellman-ford?
    vector<long long> dist(N,INF);
    dist[S] = -income[S];
    for(int iter=0;iter<N-1;++iter)
    {
        for(int here=0;here<N;++here)
        {
            if(dist[here]==INF) continue;
            for(auto there : adj[here])
            {
                if(dist[there.first] > dist[here] + there.second - income[there.first])
                {
                    dist[there.first] = dist[here] + there.second - income[there.first];
                }
            }
        }
    }
    bool update = false;
    for(int here=0;here<N;++here)
        for(auto there : adj[here])
            if(dist[there.first] > dist[here] + there.second - income[there.first] && reachable[S][here] && reachable[here][E]) 
                update = true;
    if(update)
    {
        cout << "Gee" << endl;
    }
    else
    {
        if (dist[E] == INF) cout << "gg" << endl;
        else cout << -dist[E] << endl;
    }
    return 0;
}