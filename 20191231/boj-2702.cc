#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        cout << a * b / g << ' ' << g << '\n';
    }
    return 0;
}