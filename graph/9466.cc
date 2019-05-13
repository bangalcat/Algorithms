/*
    백준 : 텀 프로젝트
    싸이클 찾기
    scc에 썼던 간선 분류를 이용했는데, degree를 이용한 방법도 있음
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

const int MAX_V = 1e5+1;

int main()
{
    int T; cin >> T;
    while(T--){
        //n <= 1e5
        int n; cin >> n;
        int adj[MAX_V];
        for (int i=1; i <= n; ++i){
            int sel;
            cin >> sel;
            adj[i] = sel;
        }
        vector<int> discovered(n+1,-1), done(n+1,0);
        int cnt = 0;
        function<int(int)> dfs = [&](int here){
            discovered[here] = cnt++;
            int size=0;
            int there = adj[here];
            if(discovered[there] == -1){ // tree edge
                size += dfs(there);
            }else if(done[there] == 0){ // back edge
                size += (discovered[here] - discovered[there] + 1);
            }
            done[here] = 1;
            return size;
        };
        int ans=0;
        for(int i=1;i<=n;++i){
            if(discovered[i] == -1)
                ans += dfs(i);
        }
        cout << n - ans << endl;
    }
    return 0;
}