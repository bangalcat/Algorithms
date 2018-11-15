#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
#include <map>
#include <vector>
#include <limits>

using namespace std;

int n,m,p;
double B[501];
double T[501][501];
double M[501][501];
double dp[101][501];
int choice[101][501];
string S[501];
const double NEGINF = -1e200;
map<string,int> inv;
string tracking(int idx, int prev){
    int choose = choice[idx][prev];
    assert(choose!=-1);
    string ret = S[choose];
    if(idx < n-1)
        ret = ret + " " + tracking(idx+1,choose);
    return ret;
}
double solve(int currIdx, int prev, vector<int> &words){
    if(currIdx==n) return 0;
    double& ret = dp[currIdx][prev];
    if(ret != 1.0) return ret;
    ret = NEGINF;
    int& choose = choice[currIdx][prev];
    choose = words[currIdx];
    for(int i=0;i<m;++i){
        double cand = (currIdx==0?B[i]:T[prev][i]) + M[i][words[currIdx]] + solve(currIdx+1,i,words);
        if(ret < cand){
            ret = cand;
            choose = i;
        }
    }
    assert(choose!=-1);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> m >> p;
    for(int i=0;i<m;i++){
        cin >> S[i];
        inv[S[i]] = i;
    }
    for(int i=0;i<m;i++){
        cin >> B[i];
        B[i] = (B[i]==0?NEGINF:log(B[i]));
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            cin >> T[i][j];
            T[i][j]=(T[i][j]==0?NEGINF:log(T[i][j]));
        }
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            cin >> M[i][j];
            M[i][j] = (M[i][j]==0?NEGINF:log(M[i][j]));
        }
    for(int i=0;i<p;i++){
        fill_n(*dp,101*501,1.0);
        memset(choice,-1,sizeof(choice));
        cin >> n;
        vector<int> words(n);
        for(int j=0;j<n;j++){
            string s; cin >> s;
            words[j] = inv[s];
        }
        solve(0,0,words);
        cout << tracking(0,0) << '\n';
    }
    return 0;
}
