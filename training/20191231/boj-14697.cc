#include <iostream>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    if(n % c == 0){
        cout << 1;
        return 0;
    }
    int cn = n / c;
    for(int i=cn; i>=0;--i) {
        int remain = n - i * c;
        if(remain % b == 0){
            cout << 1;
            return 0;
        }
        int bn = remain / b;
        for(int j=bn; j >= 0; --j){
            int remain2 = remain - j * b; 
            if(remain2 % a == 0){
                cout << 1;
                return 0;
            }
            int an = remain2 / a;
        }
    }
    cout << 0;
    return 0;
}