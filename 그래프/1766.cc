/*
    문제집
    위상정렬 문제
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjList[n+1];
    vector<int> indegrees(n+1,0);
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
        indegrees[b]++;
    }
    //들어오는 간선이 없는 노드들을 que에 push
    for(int i=1; i<=n; i++){
        if(indegrees[i]==0) 
            que.push(i);
    }
    while(!que.empty()){
        int node = que.top();
        que.pop();
        //출력
        cout << node << " ";
        auto v = adjList[node];
        //꺼낸 노드에서 나가는 간선들을 지운다
        for(auto num : v){
            //지운 노드들 중에 들어오는 간선 개수가 0이 되는 노드들 push
            if(--indegrees[num] == 0)
                que.push(num);
        }
        adjList[node].clear();
    }
    return 0;
}
