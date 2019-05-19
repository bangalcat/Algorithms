#include <iostream>

using namespace std;

int cache[32];

int f(int n){
    if(n%2) return 0;
    if(n==0) return 1;
    int& ret = cache[n];
    if(ret !=0) return ret;
    ret = f(n-2);
    for(int i=2; i<=n; i+=2)
        ret += f(n-i) * 2;
    return ret;
}

int main()
{
    int n; cin >> n;
    cout << f(n);
    return 0;
}