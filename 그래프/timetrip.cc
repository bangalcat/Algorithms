#include <iostream>
#include <vector>

using namespace std;

int V, W;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> reachable;
const int INF = 999999998;

int bellmanford(int src, int dest)
{
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;
    for(int iter=0;iter<V-1;++iter)
    {
        for(int here =0; here < V; ++here)
        {
            for(auto& there : adj[here])
            {
                int cost = there.second;
                if(upper[there.first] > upper[here] + cost)
                {
                    upper[there.first] = upper[here] + cost;
                }
            }
        }
    }
    for(int here = 0; here < V; ++here)
    {
        for(auto& there : adj[here])
        {
            int cost = there.second;
            if(upper[there.first] > upper[here] + cost)
            {
                if(reachable[src][here] && reachable[here][dest])
                    return -INF;
            }
        }
    }
    
    return upper[dest];
}

vector<vector<int>> makeReachable()
{
    for(int i=0;i<V;++i)
        reachable[i][i] = true;
    for(int k=0;k<V;++k)
    {
        for(int here=0;here<V;++here)
        {
            if(reachable[here][k])
                for(int there=0;there<V;++there)
                {
                    if(reachable[k][there])
                        reachable[here][there] = true;
                }
        }
    }
    return reachable;
}


int main()
{
    int tc; cin >> tc;
    while(tc--){
        cin >> V >> W;
        adj = vector<vector<pair<int,int>>>(V);
        reachable = vector<vector<int>>(V, vector<int>(V,0));
        for(int i=0;i<W;++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
            reachable[a][b] = true;
        }
        reachable = makeReachable();
        if(!reachable[0][1])
            cout << "UNREACHABLE\n"; 
        else{
            int shortest = bellmanford(0, 1);
            for(int i=0;i<V;++i)
                for(auto& there : adj[i])
                    there.second*=-1;
            int longest = bellmanford(0, 1);
            if(shortest == -INF) cout << "INFINITY";
            else cout << shortest;
            cout <<  ' ';
            if(longest == -INF) cout << "INFINITY";
            else cout << -longest;
            cout << '\n';
        }
    }

    return 0;
}