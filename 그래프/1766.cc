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
    for(int i=1; i<=n; i++){
        if(indegrees[i]==0) 
            que.push(i);
    }
    while(!que.empty()){
        int node = que.top();
        que.pop();
        cout << node << " ";
        auto v = adjList[node];
        for(auto num : v){
            if(--indegrees[num] == 0)
                que.push(num);
        }
        adjList[node].clear();
    }
    return 0;
}
