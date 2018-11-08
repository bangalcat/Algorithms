/*
    알고스팟 문제 : 양자화
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dp[101][11];
int arr[101];
int n,s;

//cut : 남은 자르기 개수
int solve(int begin, int cut){
    if(begin==n) return 0;
    int& ret = dp[begin][cut];
    if(ret != -1) return ret;
    int sum=0;
    ret = 999999999;
    for(int i=begin;i<n;i++){
        sum += arr[i];
        if(i < n-1 && cut==0) continue;
        if(i < n-1 && arr[i] == arr[i+1]) continue;
        int m = ceil((double)sum/(i-begin+1)-0.5);
        int vsum=0;
        for(int j=begin;j<=i;j++){
            vsum += (m-arr[j])*(m-arr[j]);
        }
        ret = min(ret,vsum+solve(i+1,cut-1));
    }
    return ret;
}
int main()
{
    int t; cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> n >> s;
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        cout << solve(0,s-1) << endl;
    }
    
    return 0;
}
