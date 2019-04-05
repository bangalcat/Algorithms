/*
    백준 : 1753 최단경로 문제
    다익스트라 기초 코드
*/
#include <iostream>
#include <queue>

using namespace std;

int V,E,K;

vector<pair<int,int>> adjList[20001];
vector<int> dijkstra;
const int INF = 999999999;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first==b.first?a.second<b.second:a.first>b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> V >> E;
    cin >> K;
    dijkstra.assign(V+1,INF);
    for(int i=0; i<E; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        adjList[u].push_back({w,v});
    }
    // 다익스트라 알고리즘
    // 한 정점에서 나머지 정점들로 가는 최단거리 알고리즘
    // 각 정점들의 최단거리를 순서대로 갱신한다.
    //priority queue로 선형탐색 시간을 O(nlogn)으로 줄인다.
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que;
    que.push({0,K});
    dijkstra[K] = 0;
    while(!que.empty()){
        auto p = que.top();
        que.pop();
        if(dijkstra[p.second] < p.first) continue;
        auto vlist = adjList[p.second];
        for(auto v : vlist){
            if(dijkstra[p.second] + v.first < dijkstra[v.second]){
                dijkstra[v.second] = dijkstra[p.second] + v.first;
                que.push({dijkstra[v.second], v.second});
            }
        }
    }
    for(int i=1;i<=V;++i){
        if(dijkstra[i] == INF) cout << "INF" << endl;
        else cout << dijkstra[i] << endl;
    }

    return 0;
}
