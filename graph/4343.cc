/*
    백준 : Artic Network
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
    return sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int s,p;
        cin >> s >> p;
        vector<double> xpos(p);
        vector<double> ypos(p);

        for (int i = 0; i < p; ++i)
        {
            cin >> xpos[i];
            cin >> ypos[i];
        }
        vector<bool> added(p, false);
        vector<double> minWeight(p, INF);
        vector<int> parent(p, -1);
        minWeight[0] = parent[0] = 0;
        priority_queue<pair<double, int>> pq;
        priority_queue<double> conn_edges;
        pq.push({0, 0});
        double ret = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if (added[u])
                continue;
            conn_edges.push(minWeight[u]);
            ret += minWeight[u];
            added[u] = true;
            for (int v = 0; v < p; ++v)
            {
                double dist = distance(xpos[v], ypos[v], xpos[u], ypos[u]);
                if (!added[v] && minWeight[v] > dist)
                {
                    parent[v] = u;
                    minWeight[v] = dist;
                    pq.push({-minWeight[v], v});
                }
            }
        }
        while(--s)
            conn_edges.pop();
        printf("%.2f\n", conn_edges.top());
    }

    return 0;
}