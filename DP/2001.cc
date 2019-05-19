#include <bits/stdc++.h>

using namespace std;

int ctnz(int n){
    if(n==0) return 0;
    return n%2 + ctnz(n>>1);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> jewel(n,-1);
    int num=0;
    for(int i=0;i<k;++i){
        int a; cin >> a;
        jewel[a-1] = num++;
    }
    const int IMP = -1;
    vector<vector<int>> capa(n, vector<int>(n,IMP));
    int dp[100][1<<14]={0};
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        capa[a][b] = capa[b][a] = c;
    }
    memset(dp,-1,sizeof(dp));
    queue<pair<int,int>> que; // (island, jewel)
    que.push({0,0});
    dp[0][0] = 0;
    int ans = 0;
    while(!que.empty()){
        auto curr = que.front();
        que.pop();
        int here = curr.first, jw = curr.second;
        if(here == 0) ans = max(ans, dp[here][jw]);
        int ct = ctnz(jw);
        for(int there=0;there<n;++there){
            int g = capa[here][there];
            if(g < ct) continue;
            int njw = jw;
            int nct = ct;
            if(jewel[there]!=-1 && !(jw & (1<<jewel[there]))) {
                njw |= (1<<jewel[there]);
                nct++;
            }
            if(dp[there][njw] < nct){
                dp[there][njw] = nct;
                que.push({there,njw});
                que.push({there,jw});
            }
        }
    }

    cout << ans;

    return 0;
}