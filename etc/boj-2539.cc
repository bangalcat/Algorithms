#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int pc; cin >> pc;
    int wc; cin >> wc;
    vector<int> colList;
    int maxRow=0;
    for(int i=0;i<wc;++i){
        int a, b;cin >> a >> b;
        maxRow = max(maxRow, a);
        colList.push_back(b);
    }
    sort(colList.begin(), colList.end());
    auto decision = [&](int k) {
        int st = -1;
        int cnt = 0;
        for(auto& it : colList) {
            if(st == -1){
                st = it;
                cnt++;
            }else if(it - st >= k) {
                st = it;
                cnt++;
            }
        }
        return cnt <= pc;
    };
    int lo = min(maxRow,c)-1, hi = min(r, c);
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else    
            lo = mid;
    }
    cout << hi << endl;
    return 0;
}