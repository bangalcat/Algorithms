/*
    ACM Craft DP 문제
    위상 정렬을 사용해야 한다고 하는데 그냥 메모화 재귀 DFS로 풀었음
    쓸데없는 조건을 추가하고
    dp[currNode] >= 0 조건을 제대로 설정하지 않아 고생함
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<long long> VLL;
class Solver{
    int N;
    VI times;
    VI dp;
    VI *adjList;
public:
    Solver(int n, VI& times, VI *adjList):N(n), times(times), adjList(adjList){
        dp.assign(n+1,-1);
    }
    
    int solve(int currNode){
        int timeFromStart=0;
        VI nodes = adjList[currNode];
        if(nodes.size()==0) return 0;
        if(dp[currNode] >= 0) return dp[currNode];
        for(auto v : nodes){
            timeFromStart = max(timeFromStart, solve(v) + times[v]);
        }
        // cout << currNode << " " << timeFromStart << endl;
        return dp[currNode] = timeFromStart;
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t_case; cin >> t_case;
    while(t_case--){
        int n,k,w;
        cin >> n >> k;
        VI times(n+1);
        VI adjList[n+1];
        for(int i=1;i<=n;i++) {
            cin >> times[i];
        }
        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            adjList[b].push_back(a);
        }
        cin >> w;
        Solver solver(n,times,adjList);
        cout<< solver.solve(w)+times[w] << '\n';
    }
    return 0;
}