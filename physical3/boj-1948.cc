#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> rAdj(n+1);
    vector<int> indegree(n,0);
    vector<int> rIndegree(n,0);
    for(int i=0;i<m;++i){
        int s, d, w;
        cin >> s >> d >> w;
        adj[s].push_back({w,d});
        rAdj[d].push_back({w,s});
        indegree[d]++;
        rIndegree[s]++;
    }
    int src, dest;
    cin >> src >> dest;
    queue<int> que;
    que.push(src);
    vector<int> dist(n+1, -1);
    dist[src] = 0;

    while(!que.empty()) {
        auto here = que.front();
        que.pop();
        for(auto& there : adj[here]) {
            if(there.first + dist[here] > dist[there.second]){
                dist[there.second] = there.first + dist[here];
            }
            if(--indegree[there.second] == 0) que.push(there.second);
        }
    }

    auto backtracking = [&]() {
        int ansCnt = 0;
        vector<bool> check(n+1, false);
        queue<int> q;
        q.push(dest);
        check[dest] = true;
        while(!q.empty()){
            int here = q.front(); q.pop();
            if(here == src) break;
            for(auto there : rAdj[here]) {
                if(check[here] && dist[here] - dist[there.second] == there.first){
                    ansCnt++;
                    check[there.second] = true;
                }
                if(--rIndegree[there.second]==0) q.push(there.second);
            }
        }
        return ansCnt;
    };
    cout << dist[dest] << '\n' << backtracking();

    return 0;
}