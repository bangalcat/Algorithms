#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T--) {
        int l, n; cin >> l >> n;
        int retMax = 0, retMin = 0;
        for(int i=0;i<n;++i) {
            int p; cin >> p;
            retMin = max(min(l - p, p), retMin);
            retMax = max(max(l - p, p), retMax);
        }
        cout << retMin << ' ' << retMax << endl;
    }
    return 0;
}