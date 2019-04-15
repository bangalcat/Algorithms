/*
    문제 이름 : 톱니바퀴
    시뮬레이션 문제
    시뮬레이션은 완전탐색과 비슷하면서도 단순한 하나의 완전한 결과를 만드는게 목표라는게 다름
    완전탐색은 최대 혹은 최소를 구하는 문제가 많음
*/
#include <iostream>
#include <algorithm>
#include <vector>
//#include <bitset>

using namespace std;
typedef vector<unsigned char> VUC;
typedef unsigned char uchar;

bool done[4] = {false};
void dfs(VUC& gears, int idx, int d){
    uchar t = gears[idx];
    if(d==1){
        t = ((t&1)<<7) | (t>>1);
    }else
        t = (t<<1)|((t&(1<<7))>>7);
    done[idx]=true;
    //cout << bitset<8>(t)<<endl;
    if(idx!=3){
        if(!done[idx+1] && ((gears[idx+1]>>1)&1)^((gears[idx]>>5)&1))
            dfs(gears,idx+1,d==1?-1:1);
    }
    if(idx!=0){
        if(!done[idx-1] && ((gears[idx-1]>>5)&1)^((gears[idx]>>1)&1))
            dfs(gears,idx-1,d==1?-1:1);
    }
    gears[idx] = t;
    done[idx]=false; 
}

int main() {
    VUC gears;
    for(int i=0;i<4;i++){
        uchar gear;
        for(int j=0;j<8;j++){
            gear<<=1;
            char t = cin.get();
            gear += t-'0';
        }
        cin.get();
        gears.push_back(gear);
    }
    int k; cin >> k;
    while(k--){
        int idx; int direction;
        cin >> idx >> direction;
        //재귀적으로 시뮬레이션
        dfs(gears,idx-1,direction);
    }
    int ans=0;
    for(int i=0,bm=1<<7;i<4;i++){
        if(bm&gears[i])
            ans+=(1<<i);
        //cout << bitset<8>(gears[i]) << endl;
    }
    cout << ans;
    return 0;
}
