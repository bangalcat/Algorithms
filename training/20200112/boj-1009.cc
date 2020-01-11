#include <iostream>

using namespace std;

int c_power(int num, int exp){
    if(exp == 1) return num;
    return c_power(num, exp/2) * c_power(num, exp/2) * (exp % 2 ? num : 1) % 10; 
}

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int ans = c_power(a, b) % 10;
        cout << (ans == 0 ? 10 : ans) << '\n';
    }
    return 0;
}