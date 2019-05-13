#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<long long> b(n);
    vector<long long> g(m);
    for(int i=0;i<n;++i)
        cin >> b[i];
    for(int i=0;i<m;++i)
        cin >> g[i];
    sort(b.begin(),b.end());   
    reverse(b.begin(),b.end());
    sort(g.begin(),g.end());   

    if(b[0] > g[0]) {
        cout << -1;
        return 0;
    }
    long long tot=0;
    for(int i=1;i<m;++i){
        tot += g[i];
    }
    tot += b[0];
    for(int i=1;i<n;++i)
        tot += b[i]*m;
    if (b[0] < g[0])
    {
        tot -= b[1];
        tot += g[0];
    }

    cout << tot;

    return 0;
}