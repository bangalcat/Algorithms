#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_V = 802;

int V;

int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
vector<vector<int>> adj;

int networkFlow(int src, int sink){
    int totFlow=0;
    while(true){
        vector<int> parent(MAX_V,-1);
        queue<int> q;
        parent[src] = src;
        q.push(src);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front(); q.pop();
            for(auto there : adj[here]){
                if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[sink] == -1) break;
        for(int p = sink; p != src; p = parent[p]){
            flow[parent[p]][p] ++;
            flow[p][parent[p]] --;
        }
        totFlow++;
    }
    return totFlow;
}


int main()
{
    int n, p;
    cin >> n >> p;
    V = n*2;
    adj = vector<vector<int>>(V);
    memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));
    for(int i=1;i<=p;++i){
        int a,b;
        cin >> a >> b;
        int u = a*2-2, v = b*2-2;
        //all in is x, all out is x+1
        capacity[u+1][v]++;
        capacity[v+1][u]++;
        adj[u+1].push_back(v);
        adj[v+1].push_back(u);
        adj[v].push_back(u+1);
        adj[u].push_back(v+1);
    }
    for(int i=0;i<n;++i){
        capacity[i*2][i*2+1] = 1;
        adj[i*2].push_back(i*2+1);
        adj[i*2+1].push_back(i*2);
    }
    cout << networkFlow(1,2);
    return 0;
}