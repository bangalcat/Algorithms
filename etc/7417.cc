#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adjlist;

int main(){
    int n; cin >> n;
    adj = vector<vector<int>>(n, vector<int>(n,0));
    adjlist = vector<vector<int>>(n);
    for(int i=0;i<n;++i){
        int ct; cin >> ct;
        while(ct--){
            int a = -1; cin >> a;
            if(a == 0) break;
            a--;
            adj[i][a]++;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(adj[i][j] > 0 && adj[i][j] == adj[j][i]){
                adj[i].push_back(j);
            }else{

            }
        }
    }
    return 0;
}