/*
    백준 : 돼지 잡기
    네트워크 플로우
    더 깔끔한 방법 - 정확히 이해되진 않음
    2002 Croatia Highschools Competitions in informatics Final Exam #1 - 2
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_V = 201;

struct Edge
{
    int target;
    int capacity, flow = 0;
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

int m, n, SRC, SINK;

int networkFlow(int source, int sink)
{
    int totFlow = 0;
    while (true)
    {
        vector<int> prev(MAX_V, -1);
        vector<Edge *> path(MAX_V);
        queue<int> q;
        prev[source] = source;
        q.push(source);
        while (!q.empty() && prev[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (auto edge : adj[here])
                if (edge->remain() > 0 && prev[edge->target] == -1)
                {
                    prev[edge->target] = here;
                    path[edge->target] = edge;
                    q.push(edge->target);
                    if (edge->target == sink)
                        break;
                }
        }
        if (prev[sink] == -1)
            break;
        int amt = INF;
        for (int i = sink; i != source; i = prev[i])
            amt = min(amt, path[i]->remain());
        for (int i = sink; i != source; i = prev[i])
            path[i]->push(amt);
        totFlow += amt;
    }
    return totFlow;
}

void makeGraph(vector<int> &cage, vector<vector<int>> &pod, vector<int> &purchase)
{
    adj = vector<vector<Edge *>>(MAX_V);
    for (int i = 1; i <= m; ++i)
    {
        //from source to first day
        if(!pod[i].empty())
            addEdge(SRC, 1+pod[i][0], cage[i]);

        if(pod[i].size()>1)
        for (int j=0;j<pod[i].size()-1;++j)
        {
            int u = pod[i][j] + 1;
            int v = pod[i][j+1] + 1;
            //to next day
            addEdge(u, v, INF);
        }
    }
    for(int i=1;i<=n;++i){
        addEdge(i+1,SINK,purchase[i]);
    }
}

int main()
{
    cin >> m >> n;
    vector<int> cage(m + 1);
    vector<vector<int>> pigOpenDays(1001);
    vector<int> purchase(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        cin >> cage[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        while (a--)
        {
            int k;
            cin >> k;
            pigOpenDays[k].push_back(i);
        }
        cin >> purchase[i];
    }
    SRC = 0, SINK = 1;
    makeGraph(cage, pigOpenDays, purchase);
    cout << networkFlow(SRC, SINK);
    return 0;
}