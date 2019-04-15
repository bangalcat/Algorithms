#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
bool reachable[500][500];
vector<int> bellmanford(vector<vector<pair<int,int>>>& adj, int src)
{
    int n = adj.size();
    vector<int> dist(n,INF);
    dist[src] = 0;
    for(int v=0;v<n;++v)
    {
        for(int i=0;i<n;++i)
        {
            for (auto there : adj[i])
            {
                if (dist[i] != INF && dist[there.first] > dist[i] + there.second)
                {
                    if (v == n - 1)
                        return vector<int>();
                    dist[there.first] = dist[i] + there.second;
                }
            }
        }
    }
    return dist;
}
void setReachable(int n)
{
    for (int k = 0; k < n; ++k)
        reachable[k][k] = true;
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            if (reachable[i][k])
                for (int j = 0; j < n; ++j)
                    reachable[i][j] = reachable[i][k] & reachable[k][j];
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        reachable[a - 1][b - 1] = true;
    }
    setReachable(n);
    auto ret = bellmanford(adj, 0);
    if (ret.empty())
        cout << -1;
    else
    {
        for (int i = 1; i < ret.size(); ++i)
        {
            if (ret[i] > INF / 2)
                ret[i] = -1;
            cout << ret[i] << '\n';
        }
    }

    return 0;
}