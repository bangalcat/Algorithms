#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    set<int> special;
    vector<vector<int>> adj(n+1);
    vector<pair<int,pair<int,int>>> edges;
    vector<pair<int,pair<int,int>>> spEdges;
    for(int i=0;i<k;++i){
        int s; cin >> s;
        special.insert(s);
    }
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(special.find(a)!=special.end() && special.find(b)==special.end()){
            spEdges.push_back({c,{a,b}});
        }else if(special.find(b)!=special.end() && special.find(a)==special.end()){
            spEdges.push_back({c,{a,b}});
        }else{
            edges.push_back({c,{a,b}});
        }
        
    }  
    if(spEdges.size() < w){
        cout << -1;
        return 0;
    }
    vector<int> rt(n+1);
    for (int i=1; i <= n; ++i){
        rt[i] = i;
    }
    function<int(int)> find = [&](int u){
        if(rt[u] == u) return u;
        return rt[u] = find(rt[u]);
    };
    function<void(int,int)> merge = [&](int u, int v){
        u = find(u), v = find(v);
        if(u==v) return;
        rt[u] = v;
    };
#define f first
#define s second
    sort(edges.begin(),edges.end());
    sort(spEdges.begin(),spEdges.end());
    int tot=0, edgeCnt=0;
    for(int i=0;i<spEdges.size();++i){
        int cost = spEdges[i].f;
        int u = spEdges[i].s.f;
        int v = spEdges[i].s.s;
        if(find(u) == find(v)) continue;
        merge(u, v);
        tot += cost;
        if(++edgeCnt == w) break;
    }
    if(edgeCnt < w){
        cout << -1;
        return 0;
    }
    for(int i=0;i<edges.size();++i){
        int cost = edges[i].f;
        int u = edges[i].s.f;
        int v = edges[i].s.s;
        if(find(u) == find(v)) continue;
        merge(u, v);
        tot += cost;
        if(++edgeCnt == n-1) break;
    }

    function<> getMinCost = [&](int curr, int sp) {
        
    };

    if(edgeCnt < n-1)
        cout << -1;
    else
        cout << tot << endl;

    return 0;
}