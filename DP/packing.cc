/*
    알고스팟 : Packing
    
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n,w;
int dp[101][1001];
bool pick[101];
vector<string> name(101);
vector<int> volume(101);
vector<int> value(101);
int totcnt=0;
int packing(int begin, int capacity){
    if(begin==n || capacity==0) return 0;
    int& ret = dp[begin][capacity];
    if(ret > 0) return ret;
    ret = packing(begin+1,capacity);
    if(capacity >= volume[begin]){
        int pack = packing(begin+1,capacity-volume[begin])+value[begin];
        if(pack > ret){
            ret = pack;
        }
    }
    return ret;
}
int tracking(int next, int capacity, vector<int>& pack){
    if(next==n) return pack.size();
    if(packing(next+1,capacity) < packing(next,capacity))
        pack.push_back(next);
    if(!pack.empty() && pack.back()==next)
        return tracking(next+1,capacity-volume[next],pack);
    else
        return tracking(next+1,capacity,pack);
}
int main()
{
    int c; cin >> c;
    while(c--){
        memset(dp,0,sizeof(dp));
        memset(pick,0,sizeof(pick));
        cin >> n >> w;
        for(int i=0;i<n;i++){
            cin >> name[i] >> volume[i] >> value[i];
        }
        int ret =  packing(0,w);
        cout << ret<< " " ;
        vector<int> list;
        cout << tracking(0,w,list) << '\n';
        for(int i=0;i<list.size();i++)
            cout << name[list[i]] << '\n';
    }
    return 0;
}
