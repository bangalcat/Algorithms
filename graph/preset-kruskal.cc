/*
    최소 스패닝 트리
    크루스칼 알고리즘
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 100;
int V;

struct DisjointSet
{
    vector<int> tree, rank;
    DisjointSet(int v):tree(v), rank(v,1){
        for(int i=0;i<v;++i)
            tree[i] = i;
    }
    int find(int u)
    {
        if(tree[u] == u) return u;
        return tree[u] = find(tree[u]);
    }
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u != v) 
        {
            if(rank[u] > rank[v]) swap(u, v);
            tree[u] = v;
            if(rank[u] == rank[v]) rank[u]++;
        }
    }
};

vector<pair<int,int>> adj[MAX_V];

int kruskal(vector<pair<int,int>>& selected)
{
    int ret = 0;
    selected.clear();
    // (가중치, (정점1, 정점2)) 의 목록을 얻는다.
    vector<pair<int,pair<int,int>>> edges;
    for(int u=0;u<V;++u)
    {
        for(auto vpair : adj[u])
        {
            int v = vpair.first; int cost = vpair.second;
            edges.push_back({cost, {u, v}});
        }
    }
    // 가중치 순으로 정렬
    sort(edges.begin(), edges.end());
    //처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(V);
    for(int i=0;i<edges.size();++i)
    {
        // 간선 (u, v)를 검사한다.
        int cost = edges[i].first;
        int u = edges[i].second.first; int v = edges[i].second.second;
        if(sets.find(u) == sets.find(V)) continue;
        sets.merge(u, v);
        selected.push_back({u, v});
        ret += cost;
    }
    return ret;
}

int main()
{
    return 0;
}