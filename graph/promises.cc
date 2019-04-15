#define LOCAL
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999999;

int V, M, N;
vector<vector<int>> adj;

int main(void)
{
#ifdef LOCAL
    auto f = freopen("test.txt", "r+", stdin);
#endif
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> V >> M >> N;
        adj = vector<vector<int>>(V, vector<int>(V,INF));      
        for(int i=0; i<M; ++i)
        {
            int a, b, c;
            cin >> a>> b>> c;
            if(adj[a][b] < c) continue;
            adj[a][b] = adj[b][a] = c;
        }
        for(int i=0;i<V;++i)
            adj[i][i] = 0;
        //floyd
        for(int k=0;k<V;++k)
        {
            for(int i=0;i<V;++i)
            {
                if(adj[i][k] != INF)
                for(int j=0;j<V;++j)
                {
                    adj[i][j] = min(adj[i][k] + adj[j][k], adj[i][j]);
                }
            }
        }
        int ret = 0;
        for(int t=0;t<N;++t)
        {
            int a, b, w;
            cin >> a >> b >> w;
            if(adj[a][b] <= w)
                ret++;
            else
            {
                for(int i=0;i<V;++i)
                {
                    for(int j=0;j<V;++j)
                    {
                        adj[i][j] = min({adj[i][j], adj[i][a] + w + adj[b][j], adj[i][b] + w + adj[a][j]});
                    }
                }
            }
        }
        cout << ret << '\n';
    }
#ifdef LOCAL
    fclose(stdin);
#endif
    return 0;
}