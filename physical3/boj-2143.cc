#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T, n, m;
    cin >> T;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A)
        cin >> i;
    cin >> m;
    vector<int> B(m);
    for (auto &i : B)
        cin >> i;
    vector<int> aSum;
    vector<int> bSum;
    for (int i=0;i<n;++i){
        int temp = 0;
        for (int j=i;j<n;++j){
            aSum.push_back(temp + A[j]);
            temp = aSum.back();
        }
    }
    for (int i=0;i<m;++i){
        int temp = 0;
        for (int j=i;j<m;++j){
            bSum.push_back(temp + B[j]);
            temp = bSum.back();
        }
    }
    sort(aSum.begin(), aSum.end(),greater<int>());
    sort(bSum.begin(), bSum.end());
    long long cnt = 0, prev = 0;
    auto bp = bSum.begin();
    for(int i = 0; i < aSum.size(); ++i) {
        int a = aSum[i];
        if(i > 0 && a == aSum[i-1]) {
            cnt += prev;
            continue;
        }
        prev = 0;
        while(bp != bSum.end() && *bp <= T - a) {
            if(*bp == T-a)
                prev++;
            bp++;
        }
        cnt += prev;
    }
    cout << cnt;
    return 0;
}