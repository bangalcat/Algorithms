#include <bits/stdc++.h>

using namespace std;

const int INF = 999999999;

int n, m;
int adj[51][51];
bool check[51][51];

int solve(){
    int e = 0;
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            if(adj[i][k] == INF) continue;
            for(int j=1;j<=n;++j){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    if(check[i][j])
                        return -1;
                    adj[i][j] = min(adj[i][k] + adj[k][j], INF);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if(adj[i][j] != INF)
                e++;
    return e;
}

int main()
{
    int T; cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cin >> n >> m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i==j) adj[i][j] = 0;
                else
                    adj[i][j] = INF;
        memset(check,0,sizeof(check));
        for(int i=0;i<m;++i){
            int a, b, c;
            cin >> a>> b >> c;
            adj[a][b] = adj[b][a] = c;
            check[a][b] = check[b][a] = true;
        }
        int e = solve();

        cout << "Case #" << tc << ": ";
        if(e == -1)
            cout << "Impossible" << endl;
        else {
            cout << e << endl;
            for(int i=1;i<=n;++i){
                for(int j=i+1;j<=n;++j){
                    if(adj[i][j] != INF)
                        cout << i << ' ' << j << ' ' << adj[i][j] << '\n';
                }
            }
        }
    }

    return 0;
}