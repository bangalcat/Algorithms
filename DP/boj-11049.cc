#include <iostream>
#include <vector>

using namespace std;

long long dp[501][501] = {0,};
pair<long long, long long> arr[501];

long long getmin(int l, int r){
    if(l >= r) return 0;
    long long &ret = dp[l][r];
    if(ret != 0) return ret;
    for(int i=l;i<r;++i){
        if(ret == 0)
            ret = getmin(l, i) + getmin(i+1, r) + arr[l].first * arr[i].second * arr[r].second;
        else
            ret = min(ret, getmin(l, i) + getmin(i+1, r) + arr[l].first * arr[i].second * arr[r].second);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n;++i){
        int r, c;
        cin >> r >> c;
        arr[i] = {r, c};
    }
    cout << getmin(0, n-1) << '\n';
    return 0;
}