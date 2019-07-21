#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    return a % b ? gcd(b, a % b) : b;
}

int main(){
    int g, l;
    cin >> g >> l;
    // gcd(a, b) = g
    // ax * g = a
    // bx * g = b
    // ax * bx * g = l
    // ax * bx = l / g
    // ax와 bx는 서로소
    l /= g;
    int ax, bx;
    for(int i=1; i * i <= l ; ++i) {
        if(l % i == 0) {
            if(gcd(l/i, i) == 1){
                ax = i, bx = l/i;
            }
        }
    }
    cout << ax * g << ' ' << bx * g;
    return 0;
}