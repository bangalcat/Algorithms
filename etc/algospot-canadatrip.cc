#include <iostream>
#include <vector>

using namespace std;

int n, k;
int l[5000];
int m[5000];
int g[5000];

bool decision(int x) {
    int ret = 0;
    for(int i=0; i < n; ++i){
        if(x >= l[i] - m[i])
            ret += (min(x, l[i]) - (l[i] - m[i])) / g[i] + 1;
    }
    return ret >= k;
}

int optimize() {
    int lo = -1, hi = 8030001;
    while(lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else 
            lo = mid;
    }
    return hi;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &k);
        for(int i=0;i<n;++i){
            scanf("%d %d %d", l+i, m+i, g+i);
        }
        printf("%d\n", optimize());
    }
    return 0;
}