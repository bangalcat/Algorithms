#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<int>& arr, int n){
    if(arr.size() < n) arr.resize(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
}

int solve(vector<int>& mtime, vector<int>& etime){
    int ans = 0, t = 0, n = mtime.size();
    vector<pair<int,int>> np;
    transform(etime.begin(),etime.end(),mtime.begin(),back_inserter(np), [](int a,int b){return make_pair(a,b);});
    sort(np.begin(),np.end(),greater<pair<int,int>>());
    for(int i=0;i<n;++i){
        t = t + np[i].second;
        ans = max(ans, t + np[i].first);
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> mtime(n);
        vector<int> etime(n);
        input(mtime, n);
        input(etime, n);
        cout << solve(mtime, etime) << '\n';
    }
    return 0;
}