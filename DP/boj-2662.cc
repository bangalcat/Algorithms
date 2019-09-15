/**
 * 기업투자. knapsack? dp문제 
 */
#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int profits[301][21];
int dp[301][21];
int bt[301][21];

// 현재 투자금 tot, 현재 회사번호 num 볼때 최대 이익
int f(int tot, int num) {
    if(num > m)
        return 0;
    int &ret = dp[tot][num];
    if(ret != -1)
        return ret;/**
 * 기업투자. knapsack? dp문제 
 */
    ret = 0;
    // 0원부터 tot까지 투자
    for(int money = 0; money <= tot; money++) {
        //현재 기업에 money만큼 투자했을때 최대값
        int temp = profits[money][num] + f(tot - money, num + 1);
        if(ret < temp) {
            ret = temp;
            // backtracking. 현재 tot만큼 투자자금 있을때, num 회사에 투자금은 money 만큼 하는것이 best
            bt[tot][num] = money;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=m;++j)
            cin >> profits[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout << f(n, 1) << '\n';
    int money = n;
    for(int i=1;i<=m;++i){
        cout << bt[money][i] << ' ';
        money -= bt[money][i];
    }
    return 0;
}