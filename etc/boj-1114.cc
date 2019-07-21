#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, k, c;
    cin >> l >> k >> c;
    vector<int> cuts(k+1,0);
    for(int i=1;i<=k;++i){
        int a; cin >> a;
        cuts[i] = l - a;
    }
    sort(cuts.begin(),cuts.end());
    cuts.push_back(l);
    k+=2;
    int minfirst=l;

    function<bool(int)> decision = [&](int len) {
        int last = 0;
        int prev = 0;
        int cnt = 0;
        for(int i=1;i<k;++i) {
            if(cuts[i] - last > len){
                if(cuts[i] - cuts[prev] > len) return false;
                last = cuts[prev];
                cnt++;
                if(cnt > c) return false;
            }
            prev = i;
        }
        return cnt <= c;
    };

    int lo = 0;
    int hi = l;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        // cout << lo << ' ' << hi << ' ' << mid << endl;
        if(decision(mid))
            hi = mid;
        else 
            lo = mid;
    }
    int last = 0;
    int prev = 0;
    int cnt = 0;
    for(int i=1;i<k;++i) {
        if(cuts[i] - last > hi){
            last = cuts[prev];
            minfirst = prev;
            cnt++;
        }
        prev = i;
    }
    if(cnt < c) minfirst = k-2;
    cout << hi << ' ' << l-cuts[minfirst];
    
    return 0;
}