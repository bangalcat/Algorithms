// 음식 평론가
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    return !b ? a : gcd(b, a % b);
}

int main() {
    int n, m, d; cin >> n >> m;
    d = m - gcd(n, m);
    cout << d;

    return 0;
}