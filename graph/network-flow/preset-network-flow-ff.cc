/*
    네트워크 유량
    포드-폴커슨 알고리즘 구현
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_V = 1000;

int V;

//capactiy[u][v] : u에서 v로 보낼 수 있는 용량
//flow[u][v] : u에서 v로 흘러들어가는 용량 (반대 방향은 음수)
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
//flow[][]를 계산하고 총 유량을 반환한다.
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

////// 인접 리스트를 이용한 네트워크 플로우//////////////
struct Edge{
    int target, capacity, flow=0;
    Edge * rev;
    int remain(){
        return capacity - flow;
    }
    void push(int amt){
        flow += amt;
        rev->flow -= amt;
    }
};

vector<Edge*> adj[MAX_V];

void addEdge(int u, int v, int capacity){
    Edge* uv = new Edge(), *vu = new Edge();
    uv->target = v;
    uv->capacity = capacity;
    uv->rev = vu;
    vu->target = u;
    vu->capacity = 0;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int main()
{
    return 0;
}