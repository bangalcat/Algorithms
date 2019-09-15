/**
 * 백준 : 평범한 배낭 문제. 0-1 knapsack. 반복적 동적 계획법 시 거꾸로 진행하는점
 */ 
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100001] = {0,};
    int value[100];
    int weight[100];
    for(int i=0;i<n;++i) {
        cin >> weight[i] >> value[i];
    }
    for(int i=0;i<n;++i){
        for(int j=k;j>=weight[i];--j){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[k] << endl;
    return 0;
}