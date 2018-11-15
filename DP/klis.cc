/*
    알고스팟 문제 : k번째 LIS 구하기
    3가지 함수 : 
            1. LIS 길이 구하는 함수.
            2. start에서 LIS 개수 구하는 함수
            3. k번째 LIS 구하는 함수
    lis(start) == lis(next)+1인 next들은 lis를 완성하는 start의 뒤에 올수 있는 후보들
    같은 깊이 상에 있는 next들은 무조건 not increasing order로 나타나게 된다
    만약 increasing order인 i와 j가 존재한다면, lis(i)에 S[j]가 포함되어야 하기 때문에 lis(i)==lis(j)가 성립할 수가 없다.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <algorithm>
#include <cassert>

using namespace std;

int n,k;
const int LIM = numeric_limits<int>::max();

int lis(int start, vector<int>& arr,vector<int>& dp){
    int& ret = dp[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int i=start+1;i<n;++i){
        if(start==-1 || arr[start] < arr[i]){
            ret = max(ret, lis(i,arr,dp)+1);
        }
    }
    return ret;
}
//start에서 lis의 개수
int lisCount(int start, vector<int>& arr, vector<int>& dp, vector<int>& cntCache){
    if(lis(start,arr,dp)==1) return 1;
    int& ret = cntCache[start+1];
    if(ret > 0) return ret;
    for(int i=start+1;i<n;++i){
        if((start==-1 || arr[start]<arr[i]) && lis(start,arr,dp)==lis(i,arr,dp)+1)
            ret = min<long long>(LIM,(long long)ret+lisCount(i,arr,dp,cntCache));
    }
    return ret;
}

//k번째 lis
void kthLis(int start, int skip, vector<int>& klis, vector<int>& arr, vector<int>& dp, vector<int>& cntCache){
    if(start != -1) klis.push_back(arr[start]);
    stack<int> followers;
    for(int next = start+1; next < n; ++next)
        if((start==-1 || arr[start] < arr[next]) && lis(start,arr,dp)==lis(next,arr,dp)+1){
            followers.push(next);
        }
    while(!followers.empty()){
        int next = followers.top();
        followers.pop();
        int cnt = lisCount(next, arr, dp, cntCache);
        if(cnt <= skip)
            skip -= cnt;
        else{
            kthLis(next, skip, klis, arr, dp, cntCache);
            break;
        }
    }
}

int main()
{
    int c; cin >> c;
    while(c--){
        cin >> n >> k; 
        vector<int> arr(n);
        vector<int> dp(n+1,-1);
        vector<int> cntCache(n+1,0);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        vector<int> ret;
        cout << lis(-1,arr,dp) - 1 << '\n';
        kthLis(-1,k-1,ret,arr,dp,cntCache);
        for(auto i : ret)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
