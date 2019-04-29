// n, m 실수하지좀 말자

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    int minCost=1001;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        minCost = min(minCost, a);
    }
    int maxSell=0;
    for(int i=0;i<m;++i){
        int b;
        cin >> b;
        maxSell = max(maxSell, b);
    }
    int nr = r;
    if(minCost < maxSell){
        nr = (r%minCost) + (r/minCost) * maxSell;
    }
    cout << max(r,nr);
    return 0;
}