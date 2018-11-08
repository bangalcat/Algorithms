/*
    알고스팟 문제 : 원주율 외우기
    시간복잡도가 O(N) N개의 부분문제에서 3개를 본다?
    한조각이 2개 이하인 경우는 제외해줘야 함
*/
#include <iostream>
#include <cstdio>
#include <limits>
#include <cstring>

using namespace std;

char arr[10002];
int dp[10001];
int n;
int classify(int s,int l){
    bool same=true;
    for(int i=s+1;i<l;i++){
        if(arr[i] != arr[i-1])
            same = false;
    }
    if(same) return 1;
    bool isPerm=true;
    for(int i=s+1;i<l;++i){
        if(arr[i]-arr[i-1]!=arr[s+1]-arr[s])
            isPerm = false;
    }
    if(isPerm){
        if(arr[s]-arr[s+1]==1 || arr[s]-arr[s+1]==-1)
            return 2;
    }
    bool zigzag=true;
    for(int i=s+2;i<l;++i){
        if(arr[i]!=arr[i-2])
            zigzag = false;
    }
    if(zigzag) return 4;
    if(isPerm) return 5;
    
    return 10;
}
int solve(int idx){
    if(idx==n) return 0;
    int& ret = dp[idx];
    if(ret != -1) return ret;
    ret = 999999999;
    for(int i=3; i<=5 && i+idx<=n;i++){
        ret = min(ret,classify(idx,idx+i)+solve(idx+i));
    }
    return ret;
}
int main()
{
    int t; cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf("%s",arr);
        n = strlen(arr);
        cout << solve(0) << endl;;
    }
    
    return 0;
}
