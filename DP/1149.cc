// RGB 거리
//i번째 집 red or green or blue
//i-1번째집 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> VVI;
class Solver{
    int N;
    VVI rgbs;
    VVI dp;
public:
    Solver(int n, VVI& vvi):N(n), rgbs(vvi) {
        dp.assign(n,vector<int>(3));
    }
    
    int solve(){
        dp[0][0] = rgbs[0][0];
        dp[0][1] = rgbs[0][1];
        dp[0][2] = rgbs[0][2];
        for(int i=0; i<N; i++){
            if(!dp[i][0]){
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgbs[i][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgbs[i][1];
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgbs[i][2];
            }
        }
        return min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
    }
};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    VVI rgb(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    Solver solver(n, rgb);
    cout << solver.solve();
    return 0;
}
