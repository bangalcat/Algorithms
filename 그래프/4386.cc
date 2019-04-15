/*
    백준 : 별자리 만들기
    MST
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const double INF = 987654321;

double distance(double x, double y, double tx, double ty)
{
    return sqrt((x-tx)*(x-tx) + (y-ty)*(y-ty));
}

int main()
{
    int n;
    cin >> n;
    vector<double> xpos(n);
    vector<double> ypos(n);

    for(int i=0;i<n;++i)
    {
        cin >> xpos[i];
        cin >> ypos[i];
    }

    vector<bool> added(n,false);
    vector<double> minWeight(n,INF);
    vector<int> parent(n, -1);
    minWeight[0] = parent[0] = 0;
    priority_queue<pair<double,int>> pq;
    pq.push({0,0});
    double ret=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(added[u]) continue;
        ret += minWeight[u];
        added[u] = true;
        for(int v=0;v<n;++v)
        {
            double dist = distance(xpos[v],ypos[v],xpos[u],ypos[u]);
            if(!added[v] && minWeight[v] > dist)
            {
                parent[v] = u;
                minWeight[v] = dist;
                pq.push({-minWeight[v], v});
            }
        }
    }
    printf("%.2f",ret);

    return 0;
}