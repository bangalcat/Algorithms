//인간 대포
//not solved

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const double INF = 1e9;

double distance(int x, int y, int tx, int ty)
{
    return sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
}

int main()
{
    int n;
    double sx, sy, tx, ty;
    cin >> sx >> sy;
    cin >> tx >> ty;
    cin >> n;
    vector<pair<double, double>> cannons;
    cannons.push_back({sx, sy});
    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        cannons.push_back({x, y});
    }
    cannons.push_back({tx, ty});
    //dijkstra??
    //need cache time
    //50m / 2s is cannon
    vector<double> times(n + 2, INF);
    vector<vector<double>> dist(n + 2, vector<double>(n + 2, INF));

    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = 0; j < n + 2; ++j)
        {
            if (i == j)
                dist[i][j] = 0;
            else
            {
                dist[i][j] = distance(cannons[i].first, cannons[i].second, cannons[j].first, cannons[j].second);
            }
        }
    }
    times[0] = 0;
    vector<bool> visited(n + 2,false);
    while (true)
    {
        double closest = INF;
        int here;
        for (int i = 0; i < n + 2; ++i)
            if (times[i] < closest && !visited[i])
            {
                here = i;
                closest = times[i];
            }
        if (closest == INF)
            break;
        visited[here] = true;
        for (int there = 1; there < n + 2; ++there)
        {
            if (visited[there]) continue;
            double nextTime;
            if (here == 0)
                nextTime = dist[0][there] / 5;
            else
                nextTime = min(dist[0][there] / 5, times[here] + min(2 + abs(50 - dist[here][there]) / 5, dist[here][there] / 5));
            times[there] = min(times[there], nextTime);
        }
    }
    cout << times[n + 1] << endl;
    return 0;
}