/*
    최소 스패닝 트리
    알고스팟 여행 경로 정하기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> adj;
vector<int> weights;
vector<pair<int, pair<int, int>>> edges;

const int INF = 987654321;

vector<int> parent;
vector<int> ranks;

int find(int u)
{
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (ranks[u] > ranks[v])
        swap(u, v);
    parent[v] = u;
    if (ranks[u] == ranks[v])
        ranks[u]++;
}

void initParent()
{
    for (int i = 0; i < parent.size(); ++i)
        parent[i] = i;
}

int kruskalMinUpperBount(int low)
{
    ranks = parent = vector<int>(N+1,1);
    initParent();
    for (auto e : edges)
    {
        int cost = e.first;
        if(cost < weights[low]) continue;
        int u = e.second.first, v = e.second.second;
        merge(u, v);
        if(find(0) == find(N-1)) return cost;
    }
    return INF;
}

int minWeightDifference()
{
    int ret = INF;
    for (int i = 0; i < N; ++i)
    {
        ret = min(ret, kruskalMinUpperBount(i) - weights[i]);
    }
    return ret;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> N >> M;
        adj = vector<vector<pair<int, int>>>(N);
        weights.clear();
        edges.clear();
        for (int i = 0; i < M; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
            weights.push_back(c);
            edges.push_back({c, {a, b}});
        }
        sort(weights.begin(), weights.end());
        sort(edges.begin(), edges.end());
        cout << minWeightDifference() << '\n';
    }
    return 0;
}