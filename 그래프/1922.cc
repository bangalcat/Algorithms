/*
    백준 : 네트워크 연결
    MST 최소 스패닝 트리
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int N, M;
vector<pair<int, pair<int, int>>> edges;

void initDisjointSet()
{
    parent = ranks = vector<int>(N, 0);
    for (int i = 0; i < N; ++i)
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
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a-1, b-1}});
    }
    cout << kruskal();
    return 0;
}