/*
    동전 1 : DP 문제
    동전을 가격 오름차순으로 주지 않는 것 주의!
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
    int K;
    VI coins;
    int dp[10001]={0};
public:
    Solver(int n, int k, VI& coins):N(n), K(k), coins(coins){
    }
    
    int solve(){
        dp[0] = 1;
        for(int i=0;i<N; i++){
            for(int sum=coins[i]; sum<=K; sum++){
                dp[sum] += dp[sum - coins[i]];
            }
        }
        return dp[K];
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    VI coins;
    while(n--){
        int coin; cin >> coin;
        coins.push_back(coin);
    }
    Solver solver(coins.size(),k,coins);
    cout << solver.solve();
    return 0;
}
