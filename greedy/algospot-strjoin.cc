#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void input(vector<int>& arr, int n){
    if(arr.size() < n) arr.resize(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
}

int solve(const vector<int>& ssize){
    int ans = 0; 
    int n = ssize.size();
    multiset<int> sset(ssize.begin(),ssize.end());
    while(sset.size() > 1){
        int t = 0;
        auto _min = sset.begin();
        t = *_min;
        sset.erase(_min);
        t += *(++_min);
        sset.erase(_min);
        sset.insert(t);
        ans += t;
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> ssize(n);
        input(ssize, n);
        cout << solve(ssize) << '\n';
    }
    return 0;
}