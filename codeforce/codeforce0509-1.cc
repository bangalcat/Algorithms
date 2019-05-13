#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    if(m <= n/2)
        cout << (m==0?1:m) << endl;
    else
        cout << n/2 - (m - n/2) + n%2 << endl;
    return 0;
}