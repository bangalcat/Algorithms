#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    vector <vector<int>> dp(n,vector<int>(11,0));
    for(int i=1;i<=9;i++)
        dp[0][i] = 1;
    for(int i=1; i<n; i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1; j<10;j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
    }
    long long sum=0;
    for(auto &i : dp[n-1])
        sum += i;
    return sum % 1000000000;
}
int main(){
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}