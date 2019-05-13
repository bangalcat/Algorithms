/*
    백준 : 토렌트 
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;
vector<vector<int>> adj;
vector<bool> visited;
int n, m;

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto v : adj[a]){
        if(B[v] == -1 || !visited[B[v]] && dfs(B[v])){
            A[a] = v;
            B[v] = a;
            return true;
        }
    }
    return false;
}

int bipartite(int startTime, int endTime){
    A = vector<int>(200,-1); B = vector<int>(200,-1);
    int size= 0;
    for(int start=startTime; start < endTime; ++ start){
        visited = vector<bool>(200,false);
        size += dfs(start);
    }
    return size;
}


int main(){
    int T; cin >> T;
    while(T--){
        cin >> n >> m;
        adj = vector<vector<int>>(101);
        int st=999, et=0; //start, end time
        for(int i=0;i<m;++i){
            int t1, t2, a_ct, q;
            cin >> t1 >> t2 >> a_ct;
            st = min(st, t1);
            et = max(et, t2);
            for (int j = 0; j < a_ct; ++j) {
                cin >> q;
                for(int t=t1; t<t2;++t)
                    adj[t].push_back(q-1);
            }
        }
        auto solve = [&](){
            int minEndTime = st + n;
            for(int mEt = minEndTime; mEt <= et; ++mEt){
                if(bipartite(st, mEt) == n)
                    return mEt;
            }
            return -1;
        };
        cout << solve() << '\n';
    }
    
    return 0;
}