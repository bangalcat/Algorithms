/*
    알고스팟 : 크리스마스 인형
    부분합
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int n, k; cin >> n >> k;
        vector<long long> psum(n+1,0);
        vector<long long> possible(n+1,-1);
        vector<long long> lastk(k+1,-1);
        //1. 한번 주문 가능할 때 가짓수
        //     (psum[r]-psum[l]) % K == 0
        //     psum[r] % K == psum[l] % K
        //2. 최대 몇번 주문?
        //     겹치지 않는 구간 최대 개수
        //     dp?
        vector<long long> mod(k,0LL);
        mod[0]++;
        lastk[0] = 0;
        for(int i=0;i<n;++i){
            int a; cin >> a;
            psum[i+1] = psum[i] + a;
            possible[i+1] = lastk[psum[i+1]%k];
            mod[psum[i+1]%k]++;
            lastk[psum[i+1]%k] = i+1;
        }
        int ans1=0, ans2=0;
        for(auto& t : mod){
            if(t) ans1 = (ans1 + t*(t-1)/2) % 20091101;
        }
        // dp[n] = n번째 상자까지 최대 가능값
        vector<int> dp(n+1,0);
        for(int i=1; i<=n ; ++i){
            int l = 0;
            if(possible[i] >= 0)
                l = dp[possible[i]]+1;
            dp[i] = max(l, dp[i-1]);
        }
        ans2 = dp[n];
        cout << ans1 << ' ' << ans2 << '\n';
    }
    
    return 0;
}