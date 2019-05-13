/*
    백준 : 단절점
    절단점 찾기 문제
*/
#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

const int INF = 987654321;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[10001];
    for(int i=0;i<e;++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> discovered(v+1,-1);
    set<int> cuts;
    int vCnt=0;
    function<int(int,bool)> dfs = [&](int here, bool isRoot){
        int ret = discovered[here] = vCnt++;
        int minDiscv;
        int childCnt=0;
        for(int there : adj[here]) {
            if(discovered[there] == -1){
                childCnt++;
                minDiscv = dfs(there, false);
                if(!isRoot && minDiscv >= discovered[here]){
                    cuts.insert(here);
                }
                ret = min(ret,minDiscv);
            }else{
                ret = min(ret, discovered[there]);
            }
        }
        if(isRoot && childCnt > 1)
            cuts.insert(here);
        return ret;
    };
    for(int i=1; i <= v; ++i){
        if(discovered[i] == -1)
            dfs(i, true);
    }
    cout << cuts.size() << endl;
    for(int a : cuts)
        cout << a << ' ';
    return 0;
}