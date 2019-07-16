#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n+1);
    for(int i=0;i<n;++i) {
        cin >> arr[i+1];
    }
    int s = 1, t = 1;
    long long ans = 0;
    map<int,int> cnt;
    while(s <= n && t <= n) {
        if(cnt[arr[t]] == 1) {
            ans += t - s;
            cnt[arr[s]]--;
            s++;
        } else{
            cnt[arr[t]]++;
            t++;
        }
    }
    ans += ((long long)t-s)*((long long)t-s+1) / 2;
    cout << ans;
    return 0;
}