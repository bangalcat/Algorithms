#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<set<int>> adjlist(n);
    for(int i=0;i<n;++i) {
        int ct; cin >> ct;
        while(ct--) {
            int a; cin >> a;
            adjlist[i].insert(a-1);
            adjlist[a-1].insert(i);
        }
    }
    queue<int> que;
    vector<int> team(n,0);
    set<int> teams[2];
    for(int i=0;i<n;++i){
        if(team[i]) continue;
        team[i] = 1;
        teams[0].insert(i+1);
        que.push(i);
        while(!que.empty()) {
            int curr = que.front(); que.pop();
            for(auto next : adjlist[curr]) {
                if(!team[next]){
                    que.push(next);
                    team[next] = 3 - team[curr];
                    teams[team[next]-1].insert(next+1);
                }
            }
        }
    }
    for(int t=0;t<2;++t){
        cout << teams[t].size()<< endl;
        for(auto a : teams[t])
            cout << a << ' ';
        cout << endl;
    }

    return 0;
}