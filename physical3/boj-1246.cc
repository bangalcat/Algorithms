#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parr(m);
    for(int i=0;i<m;++i) {
        cin >> parr[i];
    }
    sort(parr.begin(), parr.end());
    int ans_tot = 0;
    int ans_price = 0;
    for(auto pi=parr.begin(); pi != parr.end(); ++pi) {
        int cnt = min((int)(parr.end() - pi), n);
        if(ans_tot < cnt * *pi) {
            ans_tot = cnt * *pi;
            ans_price = *pi;
        }
    }
    cout << ans_price << ' ' << ans_tot;
    return 0;
}
