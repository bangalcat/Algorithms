#include <iostream>
#include <vector>

using namespace std;
const int INF = 987654321;
int main()
{
    // freopen("test.in","r",stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n,vector<int>(n,0));
   for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if (adj[i][k] && adj[k][j])
                {
                    if (adj[i][j] == 0)
                        adj[i][j] = adj[i][k] + adj[j][k];
                    else
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
    int ans = -1, val = INF;
    for(int i=0;i<n;++i)
    {
        int rel = 0;
        for(int j=0;j<n;++j)
        {
            rel += adj[i][j];
        }
        if(rel < val)
        {
            ans = i;
            val = rel;
        }
    }
    cout << ans+1;
    return 0;
}