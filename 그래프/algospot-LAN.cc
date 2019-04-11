
/*
    최소 스패닝 트리
    알고스팟 근거리 네트워크 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int V, E;
vector<int> xpos, ypos;
vector<vector<double>> adjMap;

double distance(int sx, int sy, int tx, int ty)
{
    return sqrt((sx-tx) * (sx-tx) + (sy-ty) * (sy-ty));
}
const double INF = 1e12;

double prim_pq()
{
    // 해당 정점이 트리에 포함되어 있나?
    vector<bool> added(V, false);
    // 트리에 인접한 간선 중 해당 정점에 닿는 최소 간선의 정보를 저장한다.
    vector<double> minWeight(V, INF);
    vector<int> parent(V, -1);
    // 가중치의 합을 저장할 변수
    double ret = 0;
    //0번 정점을 시작점으로:항상 트리에 먼저 추가한다.
    minWeight[0] = parent[0] = 0;
    // (-minWeight[u], u)
    priority_queue<pair<double, int>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        // 다음에 트리에 추가할 정점 u를 찾는다. 
        int u = pq.top().second;
        pq.pop();

        if(added[u]) continue;

        ret += minWeight[u];
        added[u] = true;
        // u에 인접한 간선 (u, v)들을 검사한다.
        for(int v = 0; v < V; ++v)
        {
            double weight = adjMap[u][v];
            if(!added[v] && minWeight[v] > weight)
            {
                parent[v] = u;
                minWeight[v] = weight;
                pq.push({-weight, v});
            }
        }
    }
    return ret;
}

int main()
{
    int tc; cin >> tc;
    while(tc--)
    {
        cin >> V >> E;
        adjMap = vector<vector<double>>(V,vector<double>(V,0));
        xpos = ypos = vector<int>(V);
        for(int i=0;i<V;++i)
            cin >> xpos[i];
        for(int i=0;i<V;++i)
            cin >> ypos[i];
        for(int i=0;i<V;++i)
            for(int j=0;j<V;++j)
                if(i!=j)
                    adjMap[j][i] = adjMap[i][j] = distance(xpos[i],ypos[i],xpos[j],ypos[j]);

        for(int i=0;i<E;++i)
        {
            int u, v; cin >> u >> v;
            adjMap[u][v] = adjMap[v][u] = 0;
        }
        printf("%0.10f\n",prim_pq());
    }
    return 0;
}