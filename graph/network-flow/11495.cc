#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
#define TEST

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
        capacity = flow = vector<vector<int>>(n * m + 2, vector<int>(n * m + 2, 0));
        vector<vector<int>> adj(n * m + 2);
        auto isRange = [](int n, int m, int r, int c) {
            return r >= 0 && r < n && c >= 0 && c < m;
        };
        int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
        int totAmt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int a;
                #ifndef TEST
                cin >> a;
                #else
                a = (i+j)%2;
                #endif
                for (int d = 0; d < 4; ++d)
                {
                    int nr = dr[d] + i, nc = dc[d] + j;
                    if (isRange(n, m, nr, nc))
                    {
                        adj[2 + i * m + j].push_back(2 + nr * m + nc);
                        capacity[2 + i * m + j][2 + nr * m + nc] = INF;
                    }
                }
                blue = (i+j)%2;
                if (!blue)
                {
                    adj[0].push_back(2 + i * m + j);
                    adj[2 + i * m + j].push_back(0);
                    capacity[0][2 + i * m + j] = a;
                    capacity[2 + i * m + j][0] = 0;
                }
                else
                {
                    adj[2 + i * m + j].push_back(1);
                    adj[1].push_back(2 + i * m + j);
                    capacity[1][2 + i * m + j] = 0;
                    capacity[2 + i * m + j][1] = a;
                }
                totAmt += a;
            }
        }
        int V = n * m + 2;
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
                    for (auto there : adj[here])
                    {
                        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                        {
                            parent[there] = here;
                            q.push(there);
                        }
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
        int ans = totAmt - networkFlow(0, 1);
        cout << ans << '\n';
    }
    return 0;
}