#include <iostream>

using namespace std;

// n <= 1120, k <= 14
// dp[n][k] : 합이 n인 k개 소수 경우의수
int main()
{
    int T; cin >> T;
    // prime setting
    bool erat[1121] = {false,};
    erat[1] = true;
    for(int i=2;i*i<=1120;++i) {
        if(!erat[i]) for(int j=i*i; j<=1120; j+=i) {
            erat[j] = true;
        }
    }
    int dp[1121][15] = {0,};
    for(int i=2;i<=1120;i++) {
        for(int j=0;j<i;++j)
            if(erat[j])
    }

    return 0;
}