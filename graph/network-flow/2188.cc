#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX_V = 402;

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
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+m+2);
    memset(capacity,0,sizeof(capacity));
    memset(flow,0,sizeof(flow));
    for(int i=1;i<=n;++i){
        int ct; cin >> ct;
        for(int j=0;j<ct;++j){
            int s; cin >> s;
            capacity[i+1][1+n+s]++;
            adj[i+1].push_back(1+n+s);
            adj[1+n+s].push_back(i+1);
        }
    }
    for(int i=1;i<=n;++i){
        capacity[0][i+1] = 1;
        adj[0].push_back(i+1);
    }
    for(int j=2+n;j<2+n+m;++j){
        capacity[j][1] = 1;
        adj[j].push_back(1);
    }
    V = n + m + 2;
    cout << networkFlow(0,1);
    return 0;
}