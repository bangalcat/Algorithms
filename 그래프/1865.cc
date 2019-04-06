
// problem : wormholes

#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;

int main()
{
    freopen("test.in", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, M, W;
        cin >> N >> M >> W;
        vector<vector<pair<int,int>>> adj(N);
        for (int i = 0; i < M; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a-1].push_back({b-1,c});
            adj[b-1].push_back({a-1,c});
        }
        for (int i = 0; i < W; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a-1].push_back({b-1,-c});
        }
        bool no = true;
        vector<int> dist(N,INF);
        dist[0] = 0;
        for (int k = 0; k < N; ++k)
        {
            for (int i = 0; i < N; ++i)
                for(auto there : adj[i])
                {
                    if(dist[i] != INF && dist[there.first] > dist[i] + there.second)
                    {
                        if(k == N-1) {
                            no = false;
                        }
                        dist[there.first] = dist[i] + there.second;
                    }
                }
            if(!no)break;
        }
        if (no)
            cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}