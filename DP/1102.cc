#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>

using namespace std;

int ctnz(int n){
    if(n==0) return 0;
    return n%2 + ctnz(n>>1);
}

int main()
{
    int n,p; cin >> n;
    int cost[16][16] = {0};
    string status;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> cost[i][j];
        }
    }
    cin >> status;
    cin >> p;
    int init_state = 0;
    reverse(status.begin(),status.end());
    for(auto c : status){
        init_state <<= 1;
        if(c=='Y')
            init_state |= 1;
    }

    int cache[1<<16] = {0};
    memset(cache,-1,sizeof(cache));

    function<int(int)> getMinimumCost = [&](int currState){
        if(ctnz(currState) >= p) return 0;
        int& ret = cache[currState];
        if(ret != -1) return ret;
        ret = 99999;
        int remainSet = (1<<n)-1 & ~currState;
        for(int i=0;i<n;++i){
            if((1<<i) & remainSet){
                int c = 99999;
                for(int j=0;j<n;++j){
                    if((1<<j)&currState)
                        c = min(c, cost[j][i]);
                }
                ret = min(ret, c + getMinimumCost(currState | (1<<i)));
            }
        }
        return ret;
    };
    int ans = getMinimumCost(init_state);

    cout << (ans==99999?-1:ans)<< endl;

    return 0;
}