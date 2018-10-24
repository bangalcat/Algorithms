/*
    문제 이름 : 가장 긴 감소하는 부분 수열
    LIS 같은 문제
    lower_bound/upper_bound를 이용하면 더 빠르게 풀수 있음
    수를 전부 -1을 곱하고
    lower_boud로 구한 index에 새로운 수 a를 넣고
    k가 최장길이보다 크면 최장길이+=1
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[1001];
    int dp[1001];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int i=1;i<n; i++){
        int max_dp=0;
        for(int j=0; j<i; j++)
            if(arr[j] > arr[i] && dp[j] > max_dp )
                max_dp = dp[j];
        dp[i] = max_dp+1;
    }
    int res=0;
    for(int i=0; i<n; i++)
        if(res < dp[i])
            res = dp[i];
    cout << res;
    return 0;
}