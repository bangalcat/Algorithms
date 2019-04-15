#define LOCAL
#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999999;

void floyd(vector<vector<int>> &adj)
{
    int n = adj.size();
    for(int k=0;k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
}

int main()
{
#ifdef LOCAL
    freopen("/home/semaj/workspace/algorithms/boj/그래프/input.txt","r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
    }
    for(int i=0;i<n;++i)
        adj[i][i] = 0;
    floyd(adj);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << (adj[i][j] == INF ? 0 : adj[i][j]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}