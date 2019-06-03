
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main()
{
    int L, W, H, n;
    cin >> L >> W >> H;
    cin >> n;
    vector<int> ctype(n);
    vector<int> ccnt(n);
    for(int i=n;i>=0;--i){
        cin >> ctype[i] >> ccnt[i];
    }

    function<int(int,int,int)> fill = [&](int l,int w,int h){
        int cnt=0;
        int lwh[3] = {l,w,h};
        sort(lwh,lwh+3);
        int i;
        for(i=0;i<n;++i){
            if((1 << ctype[i]) <= lwh[0] && ccnt[i] > 0)
                break;
        }
        if(i == n) {
            return -1;
        }
        int t = 1 << ctype[i];
        int tm = min(lwh[2] / t, ccnt[i]);
        ccnt[i] -= tm;
        cnt += tm;
        int d1=0, d2=0, d3=0;
        if(lwh[2] != t*tm) d1 = fill(t, t, lwh[2] - t*tm);
        if(d1 ==-1) return -1;
        if(lwh[1] != t) d2 = fill(lwh[0], lwh[1] - t, lwh[2]);
        if(d2 == -1) return -1;
        if(lwh[0] != t) d3 = fill(lwh[0] - t, t, lwh[2]);
        if(d3 == -1) return -1;

        return cnt + d1 + d2 + d3;
    };

    printf("%d",fill(L,W,H));

    return 0;
}