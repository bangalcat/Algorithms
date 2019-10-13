#include <iostream>
#include <cmath>

using namespace std;

#define MAX_D 15    // log(N)
#define MAX_N 100000    // 가능 범위

int st[MAX_N+1][MAX_D+1];

int main()
{
    int N, Q;
    cin >> N;
    int arr[MAX_N+1];
    for(int i=0;i<N;++i) {
        cin >> st[i][0];
    }
    for(int j=1;j<MAX_D;++j) {
        for(int i=0;i<N;++i) {
            st[i][j] = min(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
    cin >> Q;
    for(int i=0;i<Q;++i) {
        int l, r;
        cin >> l >> r;
        int j = log2(r-l+1);
        printf("%d\n", min(st[l][j], st[r - (1<<j) + 1][j]));
    }

    return 0;
}