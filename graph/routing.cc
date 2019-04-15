#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int N, M;
const int INF = 999999999;
vector<vector<pair<int,double>>> adj;

double solve(){
    vector<double> dist(N,0);
    priority_queue<pair<double,int>> que;
    que.push({-1,0});
    dist[0] = 1;
    while(!que.empty()){
        auto curr = que.top();
        que.pop();
        double d = -curr.first;
        int here = curr.second;
        for(auto there : adj[here]){
            if(!dist[there.first] || dist[there.first] > d * there.second){
                dist[there.first] = d * there.second;
                que.push({-dist[there.first], there.first});
            }
        }
    }
    return dist[N-1];
}

int main()
{
    int tc; cin >> tc;
    while(tc--){
        cin >> N >> M;
        adj = vector<vector<pair<int,double>>>(N);
        for(int i=0;i<M; ++i){
            int a, b;
            double c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        cout << fixed << setprecision(10) << solve() << '\n';
    }
    
    return 0;
}