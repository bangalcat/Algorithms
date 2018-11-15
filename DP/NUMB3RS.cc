/*
    알고스팟 문제 : 두니발 박사의 탈옥
    마르코프 연쇄?
*/
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[51][101];
double prob[51][51];
const int DIV = 10000000;
int n,p;
double existProb(int day, int town){
    if(day==1)
        return prob[p][town];
    double &ret = dp[town][day];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=0;i<n;i++){
        if(prob[i][town] > 0)
            ret += existProb(day-1,i)*prob[i][town];
    }
    return ret;
}
int main(){
    int c;cin >> c;
    while(c--){
        fill_n(*dp,51*101,-1.0);
        fill_n(*prob,51*51,0);
        int d,t;
        cin >> n >> d >> p;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                cin >> prob[i][j];
                if(prob[i][j] > 0)
                    cnt++;
            }
            for(int j=0;j<n;j++){
                if(prob[i][j]>0)
                    prob[i][j]/=(double)cnt;
            }
        }
        cin >> t;
        for(int i=0;i<t;i++){
            int town; cin >> town;
            cout << fixed <<setprecision(8)<< existProb(d,town) << " ";
        }
        cout << endl;
    }
    return 0;
}
