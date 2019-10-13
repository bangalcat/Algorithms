#include <iostream>
#include <cmath>

using namespace std;

#define MAX_D 16    // log(N)
#define MAX_N 50000    // 가능 범위

int st[MAX_N+1][MAX_D+1];

int main()
{
    int N, M;
    cin >> N >> M;
    int arr[MAX_N+1];
    for(int i=0;i<N;++i) {
        cin >> st[i+1][0];
    }
    for(int j=1;j<=MAX_D;++j) {
        for(int i=1;i + (1 << j) <= N+1;++i) {
            st[i][j] = max(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
    int cnt = 0;
    for(int i=0;i<M;++i) {
        int l, r;
        cin >> l >> r;
        r -= 1;
        int j = log2(r-l+1);
        // printf("%d\n", max(st[l][j], st[r - (1<<j) + 1][j]));
        cnt += (st[l][0] >= max(st[l][j], st[r - (1<<j) + 1][j]));
    }
    cout << cnt << endl;

    return 0;
}