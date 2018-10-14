/*
    LCS 최장 공통 부분 수열 찾기 문제
    if(s[i] == t[j])
        LCS[i][j] = LCS[i-1][j-1] + 1
*/
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
typedef vector<vector<int>> VVI;
typedef vector<vector<bool>> VVB;
typedef vector<int> VI;
typedef vector<bool> VB;

class Solver{
    VVI dp;
public:
    Solver(){
        dp.assign(1001,VI(1001,0));
    }
    int solve(const string& s, const string& t){
        int ret;
        int n = s.size(), m = t.size();
        dp[0][0] = s[0] == t[0];
        for(int i=1;i<n;i++)
            dp[i][0] = (dp[i-1][0] || s[i] == t[0]);
        for(int j=1;j<m;j++)
            dp[0][j] = (dp[0][j-1] || s[0] == t[j]);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int k = (s[i] == t[j]);
                if(s[i] == t[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n-1][m-1];
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    Solver solver;
    cout << solver.solve(s,t);
    return 0;
}