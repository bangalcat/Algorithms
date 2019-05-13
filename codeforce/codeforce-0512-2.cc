
#include <bits/stdc++.h>

using namespace std;
const long long INF= 1e14+10;

int main(){
    int n; cin >> n;
    vector<pair<long long,int>> arr(n);
    for(int i=0;i<n;++i){
        int a; cin >> a;
        arr[i] = {a,i};
    }
    long long k = INF;
    for(int i=0;i<n;++i){
        auto p = arr[i];
        if(p.second != 0) k = min(k, min(p.first,arr[0].first) / p.second);
        else k = min(k, min(p.first,arr[1].first));
        if(p.second != n-1) k = min(k, min(p.first,arr[n-1].first) / (n-1 - p.second));
        else k = min(k, min(p.first,arr[n-2].first));
    }
    cout << k;
    return 0;
}