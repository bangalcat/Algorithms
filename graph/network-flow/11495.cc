/*
    백준 : 격자 0 만들기
    아오 개같은 문제 진짜
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

bool isRange(int n, int m, int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
};

int main()
{
    int T;
    #ifndef TEST
    cin >> T;
    #else
    T = 10;
    #endif
    while (T--)
    {
        int n, m;
#ifndef TEST
        cin >> n >> m;
#else
        n = rand()%40+1, m = rand()%40+1;
        cout << n << ' ' << m << endl;
#endif
        int blue = 0;
        vector<vector<int>> capacity, flow;
        capacity= vector<vector<int>>(n * m+10, vector<int>(n * m+10, INF));
        flow = vector<vector<int>>(n * m+10, vector<int>(n * m+10, 0));
        vector<vector<int>> adj(n * m + 10);
        int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};
        int totAmt = 0;
        #define SRC (n*m+2)
        #define SINK (n*m+3)
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int a=0;
#ifndef TEST
                cin >> a;
#else
                a = (i+j)%2;
#endif
                totAmt += a;
                blue = (i+j)%2;

                if(!blue) for (int d = 0; d < 4; ++d)
                {
                    int nr = dr[d] + i, nc = dc[d] + j;
                    if (isRange(n, m, nr, nc))
                    {
                        adj[i * m + j].push_back(nr * m + nc);
                        capacity[i * m + j][nr * m + nc] = INF;
                        adj[nr * m + nc].push_back(i * m + j);
                        capacity[nr * m + nc][i * m + j] = 0;
                    }
                }
                if (!blue)
                {
                    adj[SRC].push_back(i * m + j);
                    adj[i * m + j].push_back(SRC);
                    capacity[SRC][i * m + j] = a;
                    capacity[i * m + j][SRC] = 0;
                }
                else
                {
                    adj[i * m + j].push_back(SINK);
                    adj[SINK].push_back(i * m + j);
                    capacity[SINK][i * m + j] = 0;
                    capacity[i * m + j][SINK] = a;
                }

            }
        }
        int V = n * m + 10;
        auto networkFlow = [&](int src, int sink) {
            int totFlow = 0;
            while (true)
            {
                queue<int> q;
                vector<int> parent(V, -1);
                q.push(src);
                parent[src] = src;
                while (!q.empty() && parent[sink] == -1)
                {
                    int here = q.front();
                    q.pop();
                    for (int there : adj[here])
                    {
                        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                        {
                            parent[there] = here;
                            q.push(there);
                        }
                        if(parent[sink] != -1) break;
                    }
                }
                if (parent[sink] == -1)
                    break;
                int amount = INF;
                for (int p = sink; p != src; p = parent[p])
                    amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
                for (int p = sink; p != src; p = parent[p])
                {
                    flow[parent[p]][p] += amount;
                    flow[p][parent[p]] -= amount;
                }
                totFlow += amount;
            }
            return totFlow;
        };
        int ans = totAmt - networkFlow(SRC, SINK);
        cout << ans << '\n';
    }
    return 0;
}