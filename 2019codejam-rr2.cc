#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, W; cin >> T >> W;
    int bm = (1<<7)-1, bm2 = (1<<8)-1;
    int D;
    for (int tc = 1; tc <= T; ++tc)
    {
        vector<int> ri(6, 0);
        long long repd;
        D = 200;
        cout << D << endl;
        cin >> repd;
        ri[3] = (repd >> 49) & bm;
        ri[4] = (repd >> 39) & bm;
        ri[5] = (repd >> 32) & bm;
        D = 56;
        // ask about day D
        cout << D << endl;
        // read respond
        cin >> repd;
        repd = repd - (ri[3]<<14) - (ri[4]<<11) - (ri[5]<<9);
        ri[0] = (repd >> 55) & bm;
        ri[1] = (repd >> 27) & bm;
        ri[2] = (repd >> 17) & bm;
        //r3 + (r4>>4)
        for (auto r : ri)
            cout << r << ' ';
        cout << endl;
        int ans;
        cin >> ans;
        assert(ans == 1);
    }
    return 0;
}