/*
    문제이름 : 문자열의 주기 예측
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> pi(n,0);
    int dp[1000001]={0};
    int match = 0;
    for(int i=1; i< n; i++){
        while(match > 0 && s[i] != s[match])
            match = pi[match -1];
        if(s[i] == s[match])
            pi[i] = ++match;
    }
    long long sum = 0;
    auto get_min_pi = [&](){
        for(int i=0; i< n ; i++){
            if(dp[pi[i]-1] > 0) dp[i] = min(pi[i],dp[pi[i]-1]);
            else dp[i] = pi[i];
            if(dp[i])
                sum += (i-dp[i]+1);
        }
    };
    get_min_pi();
    
    cout << sum;
    return 0;    
}
