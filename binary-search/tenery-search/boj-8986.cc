#include <bits/stdc++.h>

using namespace std;

long long dist(const vector<int>& arr, int inter){
    long long currPos = 0;
    long long dSum = 0;
    for(auto& p : arr) {
        dSum += abs(currPos - p);
        currPos += inter;
    }
    return dSum;
}

long long solve(const vector<int>& arr) {
    long long lo = 0;
    long long hi = arr.back();
    for(int iter = 0; iter <100 ; ++iter) {
        long long aab = (lo*2 + hi) / 3;
        long long abb = (lo + hi*2) / 3;
        if(dist(arr, aab) > dist(arr, abb)) 
            lo = aab;
        else 
            hi = abb;
    }
    long long result = 1e18;
    for(int i= lo; i <= hi ; ++i)
        result = min(result, dist(arr, i));
    return result;
}


int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin >> arr[i];
    if(n==1){
        cout << 0;
        return 0;
    }
    cout << solve(arr);
    return 0;
}