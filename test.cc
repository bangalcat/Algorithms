#include <iostream>
#include <cstdio>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
const int INF = 987654321;
const int RED = 1500;
 
int arr[55][55];
pair<int, int> map[55][55];
 
vector<int> adj[3011];
int c[3011][3011];
int f[3011][3011];
 
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
 
int S = 0, T = 3003;
 
int main()
{
    fastio();
 
    int tc;
    cin >> tc;
 
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
 
        memset(arr, 0, sizeof(arr));
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));
        memset(map, 0, sizeof(map));
 
        for (int i = 0; i < 3011; i++)
            adj[i].clear();
 
        vector<int> blue, red;
 
        int total = 0;
        bool chk = true; // blue일때 true
        int r = 1, b = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
 
                total += arr[i][j];
 
                if (chk)
                {
                    blue.push_back(arr[i][j]);
                    map[i][j] = { 1, b++ };
                }
                else
                {
                    red.push_back(arr[i][j]);
                    map[i][j] = { -1, r++ };
                }
                chk = !chk;
            }
            if (m % 2 == 0)
                chk = !chk;
        }
 
        r = 1 + RED, b = 1;
 
        for (int i = 0; i < blue.size(); i++)
        {
            c[S][b] = blue[i];
 
            adj[S].push_back(b);
            adj[b].push_back(S);
 
            b++;
        }
 
        for (int i = 0; i < red.size(); i++)
        {
            c[r][T] = red[i];
 
            adj[r].push_back(T);
            adj[T].push_back(r);
 
            r++;
        }
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j].first == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dy[k];
                        int nj = j + dx[k];
 
                        if (!(0 <= ni && ni < n) || !(0 <= nj && nj < m))
                            continue;
 
                        int b = map[i][j].second;
                        int r = map[ni][nj].second + RED;
                        c[b][r] = INF;
 
                        adj[b].push_back(r);
                        adj[r].push_back(b);
                    }
                }
 
            }
 
        }
 
        int totalFlow = 0;
 
        while (1)
        {
            vector<int> prev(3004, -1);
 
            queue<int> q;
            q.push(S);
 
            while (!q.empty() && prev[T] == -1)
            {
                int here = q.front();
                q.pop();
 
                for (int i = 0; i < adj[here].size(); i++)
                {
                    int next = adj[here][i];
                    if (prev[next] != -1)
                        continue;
 
                    if (c[here][next] - f[here][next] > 0)
                    {
                        q.push(next);
                        prev[next] = here;
                    }
                }
            }
            if (prev[T] == -1)
                break;
 
            int flow = INF;
 
            for (int i = T; i != S; i = prev[i])
                flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
 
            for (int i = T; i != S; i = prev[i])
            {
                f[prev[i]][i] += flow;
                f[i][prev[i]] -= flow;
            }
            cout << flow << endl;
            totalFlow += flow;
 
        }
 
        cout << total - totalFlow << endl;
    }
    return 0;
}
