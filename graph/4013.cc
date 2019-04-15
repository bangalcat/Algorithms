#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> sccAdjList;
vector<int> sccIndegree;
vector<int> hasRest;
vector<int> sccHasRest;
vector<int> cash;
vector<int> sccCash;
vector<int> sccMaxCash;

stack<int> st;
vector<int> discovered;
vector<int> sccIds;
int vCount;
int sccCount;
int sStart;
int start;

int scc(int here){
    st.push(here);
    discovered[here] = ++vCount;
    int ret = discovered[here];
    for(int i=0;i<adj[here].size();++i){
        int there = adj[here][i];
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        else if(sccIds[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if(ret == discovered[here]){
        while(true){
            int t = st.top();
            st.pop();
            sccIds[t] = sccCount;
            if(t == here) break;
        }
        sccCount++;
    }
    return ret;
}

int tarjanSCC(int v, int e){
    discovered = vector<int>(v,-1);
    sccIds = vector<int>(v,-1);
    vCount = sccCount = 0;
    int ans=0;
    for(int i=0;i<v;++i){
        if(discovered[i] == -1){
            scc(i);
        }
    }
    sccHasRest = sccCash = sccMaxCash = sccIndegree = vector<int>(sccCount,0);
    sccAdjList = vector<vector<int>>(sccCount);
    for(int i=0;i<v;++i){
        if(i==start-1) sStart = sccIds[i];
        sccCash[sccIds[i]] += cash[i];
        if(hasRest[i])
            sccHasRest[sccIds[i]] = true;
        for(int there : adj[i]){
            if(sccIds[i] != sccIds[there]){
                sccAdjList[sccIds[i]].push_back(sccIds[there]);
                sccIndegree[sccIds[there]]++;
            }
        }
    }
    vector<int> isConnected(sccCount,0);
    queue<int> que;
    for(int i=0;i<sccCount;++i){
        sccMaxCash[i] = sccCash[i];
        if(sccIndegree[i]==0){
            que.push(i);
        }
    }
    isConnected[sStart] = true;
    while(!que.empty()){
        int p = que.front();
        que.pop();
        for(auto t : sccAdjList[p]){
            if(isConnected[p]){
                isConnected[t] = true;
                sccMaxCash[t] = max(sccMaxCash[p]+sccCash[t], sccMaxCash[t]);
            }
            sccIndegree[t]--;
            if(!sccIndegree[t])
                que.push(t);
        }
    }
    for(int i=0;i<sccCount;++i){
        if(sccHasRest[i] && isConnected[i]) ans = max(ans, sccMaxCash[i]);
    }
    return ans;
}

int main()
{
    int n, m, p;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    cash = hasRest = vector<int>(n,0);
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    for(int i=0;i<n;++i){
        cin >> cash[i];
    }
    cin >> start >> p;
    for(int i=0;i<p;++i){
        int a; cin >> a;
        hasRest[a-1] = true;
    }
    cout << tarjanSCC(n, m);

    return 0;
}