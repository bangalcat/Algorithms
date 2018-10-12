/*
    포도주 시식 문제
    경우의 수 3가지
    1. 3번째 전까지와 1번째 전 와인과 현재 와인 마시는 경우(2번째 전을 건너뜀)
    2. 2번째 전 와인과 현재 와인 마시는 경우 (1번째 전을 건너뜀)
    3. 첫번째 전 와인까지 마시는 경우(현재 와인을 건너 뜀)
    dp[i] = max ( dp[i-3] + wine[i-1] + wine[i] , dp[i-2] + wine[i], dp[i-1] )
*/
#include<iostream>
using namespace std;
int arr[10001]={0};
int d[10001]={0};
int max(int a, int b, int c){
    if(a > b){
        if(a > c)
            return a;
        else
            return c;
    }else
        return b > c ? b : c;
}
int solve(int n){
    d[1] = arr[1];
    d[2] = arr[1] + arr[2];
    for(int i=3; i<=n ; i++){
        d[i] = max(d[i-3]+arr[i-1]+arr[i], d[i-2]+arr[i], d[i-1]);
    }
    return d[n];
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n ; i++){
        cin >> arr[i];
    }
    cout << solve(n);
    return 0;
}