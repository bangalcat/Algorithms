/*
    백준 : 행성 터널
    MST
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e14;

int N;
vector<vector<int>> adj;

int calcCost(int x, int y, int z, int tx, int ty, int tz)
{
    return min({abs(x - tx), abs(y - ty), abs(z - tz)});
}

struct Planet
{
    int x, y, z, i;
    Planet(int x, int y, int z, int i) : x(x), y(y), z(z), i(i) {}
};

void makeGraph(vector<Planet> &pos)
{
    adj = vector<vector<int>>(N);
    auto cmp = [](Planet a, Planet b){
        return a.x < b.x;
    };
    sort(pos.begin(),pos.end(),cmp);
    for (int i = 0; i < N-1; ++i)
    {
        adj[pos[i].i].push_back(pos[i+1].i);
        adj[pos[i+1].i].push_back(pos[i].i);
    }
    auto cmp1 = [](Planet a, Planet b){
        return a.y < b.y;
    };
    sort(pos.begin(),pos.end(),cmp1);
    for (int i = 0; i < N-1; ++i)
    {
        adj[pos[i].i].push_back(pos[i+1].i);
        adj[pos[i+1].i].push_back(pos[i].i);
    }
    auto cmp2 = [](Planet a, Planet b){
        return a.z < b.z;
    };
    sort(pos.begin(),pos.end(),cmp2);
    for (int i = 0; i < N-1; ++i)
    {
        adj[pos[i].i].push_back(pos[i+1].i);
        adj[pos[i+1].i].push_back(pos[i].i);
    }
    auto cmp3 = [](Planet a, Planet b){
        return a.i < b.i;
    };
    sort(pos.begin(),pos.end(),cmp3);
}

int main()
{
    cin >> N;
    vector<Planet> pos;
    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pos.push_back({x, y, z, i});
    }
    makeGraph(pos);
    vector<int> added(N, 0);
    vector<long long> minWeight(N, INF);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});
    minWeight[0] = 0;
    long long ret = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if (added[u])
            continue;

        ret += minWeight[u];
        added[u] = true;
        for (auto e : adj[u])
        {
            long long cost = calcCost(pos[u].x, pos[u].y, pos[u].z, pos[e].x, pos[e].y, pos[e].z);
            if (!added[e] && minWeight[e] > cost)
            {
                minWeight[e] = cost;
                pq.push({-cost, e});
            }
        }
    }
    cout << ret;
    return 0;
}