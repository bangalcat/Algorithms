#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    int dp[2001][2001] = {0, };
    for(int i=0;i<n;++i){
        dp[i][i] = 1;
    }
    for(int i=0;i<n-1;++i){
        if(arr[i] == arr[i+1])
            dp[i][i+1] = 1;
    }
    for(int k=3;k<=n;++k){
        for(int s=0;s<n-k+1;++s){
            int e = s + k - 1;
            if(arr[s] == arr[e] && dp[s+1][e-1])
                dp[s][e] = 1;
        }
    }
    int m;
    cin >> m;
    for(int i=0;i<m;++i){
        int s,e;
        cin >> s >> e;
        cout << dp[s-1][e-1] << '\n';
    }

    return 0;
}