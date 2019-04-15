#define DEBUG
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 999999999;

vector<vector<pair<int,int>>> adj;
int V, E, N, M;
vector<int> burn;
vector<int> fireStation;

int dijkstra(int start, vector<vector<int>>& dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start][start] = 0;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int d = -curr.first;
        int here = curr.second;
        for(auto there : adj[here]){
            if(dist[start][there.first]==-1 || dist[start][there.first] > d + there.second){
                dist[start][there.first] = d + there.second;
                pq.push({-dist[start][there.first], there.first});
            }
        }
    }
    int ans = INF;
    for(int i=0;i<M;++i){
        ans = min(ans, dist[start][fireStation[i]]);
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    int tc;
    cin >> tc;
    while(tc--){
        cin >> V >> E >> N >> M;
        adj = vector<vector<pair<int,int>>>(V);
        burn = vector<int>(N);
        fireStation = vector<int>(M);
        for(int i=0;i<E;++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a-1].push_back({b-1,c});
            adj[b-1].push_back({a-1,c});
        }
        for(int i=0;i<N;++i){
            cin >> burn[i];
            burn[i]--;
        }
        for(int i=0;i<M;++i){
            cin >> fireStation[i];
            fireStation[i]--;
        }
        //each burn place
        vector<vector<int>> dist(V, vector<int>(V,-1));
        int ret = 0;
        for(int i=0;i<N;++i)
            ret += dijkstra(burn[i], dist);
        cout << ret << '\n';
    }

    return 0;
}
