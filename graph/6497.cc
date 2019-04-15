/*
    백준 : 전력난
    MST
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

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

vector<pair<int, pair<int, int>>> edges;

void initDisjointSet()
{
    parent = ranks = vector<int>(m, 0);
    for (int i = 0; i < m; ++i)
        parent[i] = i;
}

int kruskal()
{
    initDisjointSet();
    sort(edges.begin(), edges.end());
    int ret = 0;
    for (auto e : edges)
    {
        int cost = e.first;
        int u = e.second.first, v = e.second.second;
        if (find(u) == find(v))
            continue;
        merge(u, v);
        ret += cost;
    }
    return ret;
}

int main()
{
    cin >> m >> n;
    while (m || n)
    {
        int tot = 0;
        edges.clear();
        for (int i = 0; i < n; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
            tot += c;
        }
        cout << tot - kruskal() << '\n';
        cin >> m >> n;
    }
    return 0;
}
