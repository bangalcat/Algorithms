/*
    포*코 코테에 나왔던 카드 문제와 유사. 단 동전 가격이 순서대로 주어지지 않음
    핵심은 dp의 범위가 가격이고 값이 최소 동전 수라는것
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> dp(k+1,-1);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        int coin;
        cin >> coin;
        for(int num=coin;num <= k;num++){
            if(dp[num-coin] >= 0){
                if(dp[num] >= 0 )
                    dp[num] = min(dp[num-coin]+1, dp[num]);
                else
                    dp[num] = dp[num-coin] + 1;
            }
        }
    }
    cout << dp[k];
    return 0;
}