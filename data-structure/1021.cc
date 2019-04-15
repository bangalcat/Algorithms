#include <iostream>
#include<vector>
#include <deque>

using namespace std;

// deque 앞에서 꺼내서 뒤에다 집어넣는 반복

int solve(deque<int> &dq, vector<int> &V){
    int ret = 0;
    for(auto k : V){
        int cur=0;
        while(dq.front()!=k){
            dq.push_back(dq.front());
            dq.pop_front();
            cur++;
        }
        ret = ret + (cur>dq.size()/2? dq.size() - cur : cur);
            
        dq.pop_front();
    }
    return ret;
}

int main()
{
    int n,m; cin >> n>>m;
    deque<int> dq;
    vector<int> V(m);
    for(int i=1;i<=n;i++)
        dq.push_back(i);
    for(int i=0;i<m;i++)
        cin >> V[i];
    cout << solve(dq,V);
    return 0;
}