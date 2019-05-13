/*
    백준 : 마피아
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 402;
const int INF = numeric_limits<int>::max();

int main(){
    int n, m;   
    int src, sink;
    vector<vector<int>> adj(MAX_V);
    vector<vector<int>> capacity;
    vector<vector<int>> flow;

    cin >> n >> m;
    cin >> src >> sink;

    flow = capacity = vector<vector<int>>(MAX_V,vector<int>(MAX_V,0));

    src = src * 2 - 2;
    sink = sink * 2 - 1;
    for(int i=0;i<n;++i){
        int cost;
        cin >> cost;
        adj[i*2].push_back(i*2+1);
        adj[i*2+1].push_back(i*2);
        capacity[i*2][i*2+1] = cost;
    }
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a*2+1].push_back(b*2);
        adj[b*2].push_back(a*2+1);
        adj[b*2+1].push_back(a*2);
        adj[a*2].push_back(b*2+1);
        capacity[a*2+1][b*2] = INF;
        capacity[b*2][a*2+1] = 0;
        capacity[b*2+1][a*2] = INF;
        capacity[a*2][b*2+1] = 0;
    }

    int totFlow = 0;
    //edmond
    while(true){
        vector<int> prev(MAX_V,-1);
        queue<int> q;
        q.push(src);
        prev[src] = src;
        while(!q.empty() && prev[sink] == -1){
            int here = q.front(); 
            q.pop();
            for(int there : adj[here]){
                if(capacity[here][there] - flow[here][there] > 0 && prev[there] == -1){
                    prev[there] = here;
                    q.push(there);
                }
            }
        }
        if(prev[sink] == -1) break;
        int amt=INF;
        for(int p = sink; p != src; p=prev[p])
            amt = min(amt, capacity[prev[p]][p] - flow[prev[p]][p]);
        
        for(int p = sink; p != src; p=prev[p]){
            flow[prev[p]][p] += amt;
            flow[p][prev[p]] -= amt;
        }
        totFlow += amt;
    }
    queue<int> q;
    q.push(src);
    vector<bool> reachable(n*2+1,false);
    reachable[src] = true;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        if(here == sink) break;
        for(int there : adj[here]){
            if(!reachable[there] && capacity[here][there] - flow[here][there] > 0){
                reachable[there] = true;
                q.push(there);
            }
        }
    }
    set<int> ans;
    for(int i=0; i < n ; ++i){
        if(reachable[i*2] && !reachable[i*2+1])
            ans.insert(i);
    }
    for(auto a : ans)
        cout << a+1 << ' ';

    return 0;
}