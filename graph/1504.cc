#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    // freopen("test.in", "r", stdin);
    int N, E;
    cin >> N >> E;
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        adj[b - 1].push_back({a - 1, c});
    }
    int k1, k2;
    cin >> k1 >> k2;
    k1--;
    k2--;
    int b = 0;
    b = (k1 == 0) | (k2 == 0) << 1;
    long long dist[4][800] = {0};
    memset(dist,-1,sizeof(dist));
    priority_queue<pair<int,pair<long long,int>>> pq;
    pq.push({-b, {0, 0}});
    dist[b][0] = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        int pass = -curr.first;
        long long cost = -curr.second.first;
        int here = curr.second.second;
        pq.pop();
        if (dist[pass][here] >= 0 && dist[pass][here] < cost)
            continue;
        for (auto there : adj[here])
        {
            int bm = 0;
            bm = (there.first == k1) | (there.first == k2)<<1;
            if (dist[pass | bm][there.first]==-1 || dist[pass | bm][there.first] > cost + there.second)
            {
                dist[pass | bm][there.first] = cost + there.second;
                pq.push({-(pass | bm),{ -(cost + there.second), there.first}});
            }
        }
    }
    if (dist[3][N - 1] == 0)
        cout << -1 << '\n';
    else
        cout << dist[3][N - 1] << '\n';
    return 0;
}