/*
    백준 : 복도 뚫기
    MST
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

const double INF = 9987654321;

struct Sensor
{
    int x, y, r;
    Sensor(int x, int y, int r):x(x),y(y),r(r){}
};

int W, N;
vector<Sensor> slist;

double calcInter(int s1, int s2)
{
    int xd = slist[s1].x-slist[s2].x;
    int yd = slist[s1].y-slist[s2].y;
    double ret = sqrt((double)xd*xd+(double)yd*yd) - slist[s1].r - slist[s2].r;
    if(ret <0) return 0;
    return ret;
}

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

vector<pair<double,pair<int,int>>> edges;

double kruskal()
{
    if(N==0) return W;
    double ret = 0;
    sort(edges.begin(), edges.end());
    //처음엔 모든 정점이 서로 분리되어 있다.
    DisjointSet sets(N+2);
    for(int i=0;i<edges.size();++i)
    {
        // 간선 (u, v)를 검사한다.
        double cost = edges[i].first;
        int u = edges[i].second.first; int v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        ret = max(ret, edges[i].first);
        if(sets.find(N) == sets.find(N+1)) break;
    }
    return ret;
}


int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        scanf("%d %d", &W, &N);
        slist.clear();
        edges.clear();
        for(int i=0;i<N;++i)
        {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            slist.push_back({x,y,r});
        }
        //0 is left wall, N+1 is right wall
        for (int i = 0; i < N; ++i)
        {
            for(int j = 0;j<N;++j){
                edges.push_back({calcInter(i, j),{i,j}});
            }
            int s1=slist[i].x - slist[i].r;
            if(s1 < 0) s1 = 0;
            edges.push_back({s1, {i, N}});
            int s2 = W - slist[i].x - slist[i].r;
            if(s2 < 0) s2 = 0;
            edges.push_back({s2, {i, N+1}});
        }
        printf("%f\n", kruskal() / 2);
    }
    return 0;
}