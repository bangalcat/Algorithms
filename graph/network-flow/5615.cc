/*
    백준 : 완전 중요한 간선
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;
int n, m;

struct Edge
{
    int target;
    char capacity, flow = 0;
    Edge *rev;
    int remain()
    {
        return capacity - flow;
    }
    void push(int amt)
    {
        flow += amt;
        rev->flow -= amt;
    }
};

vector<vector<Edge *>> adj;

void addEdge(int u, int v, int capacity)
{
    Edge *uv = new Edge(), *vu = new Edge();
    uv->target = v;
    uv->capacity = capacity;
    uv->rev = vu;
    vu->target = u;
    vu->capacity = 0;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int V;
vector<vector<int>> capa, flow;

int networkflow(int src, int sink)
{
    int totFlow = 0;
    while (true)
    {
        vector<int> prev(V, -1);
        vector<Edge *> path(V);
        queue<int> q;
        q.push(src);
        while (!q.empty() && prev[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (auto edge : adj[here])
            {
                if (edge->remain() > 0 && prev[edge->target] == -1)
                {
                    prev[edge->target] = here;
                    path[edge->target] = edge;
                    q.push(edge->target);
                }
            }
        }
        if (prev[sink] == -1)
            break;
        int amt = INF;
        for (int i = sink; i != src; i = prev[i])
            amt = min(amt, path[i]->remain());
        for (int i = sink; i != src; i = prev[i])
            path[i]->push(amt);

        totFlow += amt;
    }
    return totFlow;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d", &n, &m);
        adj = vector<vector<Edge*>>(n);
        for (int i = 0; i < m; ++i)
        {
            int f, t, b;
            scanf("%d %d %d", &f, &t, &b);
            f--, t--;
            addEdge(f, t, b);
        }
        V = n;
        int tot = networkflow(0, n - 1);
        int ans = 0;
        // find full edges
        for (int i = 0; i < n; ++i)
        {
            for (auto e : adj[i])
            {
                if(e->capacity > 0 && e->remain() == 0)
                {
                    vector<int> prev(V, -1);
                    queue<int> q;
                    q.push(i);
                    prev[i] = i;
                    while (!q.empty() && prev[e->target] == -1)
                    {
                        int here = q.front();
                        q.pop();
                        for (auto ee : adj[here])
                        {
                            if (ee->remain() > 0 && prev[ee->target] == -1)
                            {
                                prev[ee->target] = here;
                                q.push(ee->target);
                                if (ee->target == e->target)
                                    break;
                            }
                        }
                    }
                    if (prev[e->target] == -1)
                        ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}