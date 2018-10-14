/*
    문제 이름 : 파일 합치기
    DP
*/

#include<iostream>
#include<queue>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        priority_queue<int, vector<int>, greater<int>> fSizesQ;
        vector<int> fSizes;
        vector<vector<int>> dp(k+1,vector<int>(k+1,0));
        vector<vector<int>> sum(k+1,vector<int>(k+1,0));
        for(int i=0;i<k;i++){
            int num;
            cin >> num;
            fSizes.push_back(num);
            sum[i+1][i+1] = num;
            for(int j=0;j<i;j++)
                sum[j+1][i+1] = sum[j+1][i]+num;
        }
        for(int i=k-1;i>0;i--){
            for(int j=i+1;j<=k;j++){
                int minp=99999999;
                for(int p=i;p<j;p++){
                    minp = min(minp, dp[i][p] + dp[p+1][j]);
                }
                dp[i][j] = minp + sum[i][j];
            }
        }
        int ret=0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++)
                cout << setw(3) << dp[i][j] << " ";
            cout << '\n';
        }
        cout << dp[1][k] << '\n';
    }
    return 0;
}