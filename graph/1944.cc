/*
    백준 : 복제 로봇
    MST
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
vector<string> maze;
vector<vector<pair<int, int>>> adj;
map<pair<int, int>, int> keys;

int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
bool isRange(int r, int c, int n)
{
    return r >= 0 && r < n && c >= 0 && c < n;
}

int bfs(int num, int srcr, int srcc)
{
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> que;
    que.push({srcr, srcc});
    dist[srcr][srcc] = 0;
    while (!que.empty())
    {
        auto here = que.front();
        que.pop();
        int w = dist[here.first][here.second];
        if (maze[here.first][here.second] == 'K' && !(srcr == here.first && srcc == here.second))
            adj[num].push_back({keys[{here.first, here.second}],w});
        for (int d = 0; d < 4; ++d)
        {
            int nr = here.first + dr[d], nc = here.second + dc[d];
            if (isRange(nr, nc, N) && maze[nr][nc] != '1')
            {
                if (dist[nr][nc] == -1)
                {
                    dist[nr][nc] = w + 1;
                    que.push({nr, nc});
                }
            }
        }
    }
    return adj[num].size();
}

int prim_pq()
{
    vector<bool> added(M+1,0);
    vector<int> minWeight(M+1,INF);
    int ret = 0;
    minWeight[0] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(added[u]) continue;
        added[u] = true;
        ret += minWeight[u];
        for(auto p : adj[u])
        {
            int v = p.first, w = p.second;
            if(!added[v] && minWeight[v] > w)
            {
                minWeight[v] = w;
                pq.push({-w,v});
            }
        }
    }
    return ret;
}

int main()
{
    cin >> N >> M;
    maze = vector<string>(N);
    pair<int, int> start;
    int keycnt = 0;
    adj = vector<vector<pair<int, int>>>(M+1);
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        maze[i] = s;
        for (int j = 0; j < N; ++j)
            if (s[j] == 'S')
                start = {i, j};
            else if (s[j] == 'K')
                keys[{i, j}] = ++keycnt;
    }
    // for each key and start point, calc every key distance
    int cnt = bfs(0,start.first,start.second);
    if(cnt < M)
    {
        cout << -1;
        return 0;
    }
    for (auto p : keys)
    {
        bfs(p.second,p.first.first,p.first.second);
    }
    cout << prim_pq();

    return 0;
}