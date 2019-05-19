#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i=0; i < n; ++i){
        int a; cin >> a;
        arr.push_back(abs(a));
    }
    sort(arr.begin(),arr.end());
    long long cnt=0;
    for(int x=0;x<n-1;++x){
        if(arr[x]==0) continue;
        int lim = arr[x] * 2 + 1;
        auto up = lower_bound(arr.begin()+x+1, arr.end(), lim);
        cnt += (up - arr.begin() - x - 1);
    }
    cout << cnt;
    return 0;
}