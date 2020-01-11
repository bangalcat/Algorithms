#include <iostream>

using namespace std;

long long kngfib[100];

int main()
{
    kngfib[1] = kngfib[0] = 1;
    kngfib[2] = 2;
    kngfib[3] = 4;
    for(int i=4;i<=67;++i) {
        kngfib[i] = kngfib[i-1] + kngfib[i-2] + kngfib[i-3] + kngfib[i-4];
    }
    int T; cin >> T;
    while(T--) {
        int a; cin >> a;
        cout << kngfib[a] << '\n';
    }

    return 0;
}