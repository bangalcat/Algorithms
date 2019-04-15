#include <iostream>
using namespace std;
int main()
{
    freopen("test.in","r",stdin);
    int n; cin >> n;
    int adj[101][101]={0};
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin >> adj[i][j];
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            if(adj[i][k]) for(int j=0;j<n;++j)
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout << adj[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}