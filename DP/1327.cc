#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> correct(n);
    map<vector<int>,int> dp;
    for(int i=0;i<n;++i) cin >> arr[i], correct[i] = i+1;
    queue<vector<int>> que;
    que.push(arr);
    dp[arr] = 1;
    while(!que.empty()){
        auto curr = que.front();
        que.pop();
        if(curr == correct) {
            cout << dp[curr]-1 << endl;
            return 0;
        }
        int ct = dp[curr];
        for(int i=0;i<n-k+1;++i){
            vector<int> next = curr;
            reverse(next.begin()+i,next.begin()+i+k);
            if(dp[next]==0 || dp[next] > ct + 1){
                dp[next] = ct + 1;
                que.push(next);
            }
        }
    }
    cout << -1;
    return 0;
}