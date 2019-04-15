/*
    백준 : 도시 분할 계획
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

int merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (ranks[u] > ranks[v])
        swap(u, v);
    parent[v] = u;
    if (ranks[u] == ranks[v])
        ranks[u]++;
    return true;
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
    int cnt = 0;
    for (auto e : edges)
    {
        int cost = e.first;
        int u = e.second.first, v = e.second.second;
        if (find(u) == find(v))
            continue;
        if(merge(u, v))
        {
            ret += cost;
            if(++cnt == n-2) return ret;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    edges.clear();
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a-1, b-1}});
    }
    cout << kruskal() << '\n';
    return 0;
}
