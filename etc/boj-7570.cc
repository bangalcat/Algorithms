#include <iostream>
#include <vector>

using namespace std;

// 줄 세우기

int main() {
    int n; cin >> n;
    int ans = 0;
    vector<int> dp(n+1,0);
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        ans = max(dp[a], ans);
    }
    cout << n - ans;
    return 0;
}