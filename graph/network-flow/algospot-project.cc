/*
    알고스팟 : 국책사업
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <numeric>

using namespace std;

const int INF = 987654321;
const int MAX_V = 1000;

int V;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int networkFlow(int source, int sink)
{
    //flow를 0으로 초기화한다.
    memset(flow,0,sizeof(flow));
    int totFlow = 0;
    while(true)
    {
        //너비 우선 탐색으로 증가 경로를 찾는다.
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 0; there < V; ++there)
                //잔여 용량이 남아있는 간선을 따라 탐색한다.
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
        }
        //증가 경로가 없으면 종료한다.
        if (parent[sink] == -1)
            break;
        //증가 경로를 통해 유량을 얼마나 보낼지 결정한다.
        int amount = INF;
        for (int p = sink; p != source; p = parent[p])
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        //증가 경로를 통해 유량을 보낸다
        for (int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totFlow += amount;
    }
    return totFlow;
}

int maxProfit(int n,int m, vector<int>& profit){
    int SRC = 0, SINK = n+m+1;
    V = n+m+2;
    int SUM = accumulate(profit.begin(), profit.end(),0);
    int C = networkFlow(SRC, SINK);
    return SUM - C;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        memset(capacity,0,sizeof(capacity));
        vector<int> profit(n);
        vector<int> cost(m);
        for(int i=0;i<n;++i){
            cin >> profit[i];
            //from source
            capacity[0][i+1] = profit[i];
        }
        for(int i=0;i<m;++i){
            cin >> cost[i];
            //to sink
            capacity[n+1+i][n+m+1] = cost[i];
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int need; cin >> need;
                if(need)
                    capacity[i+1][n+j+1] = INF;
            }
        }
        cout << maxProfit(n,m,profit) << '\n';
    }
    return 0;
}