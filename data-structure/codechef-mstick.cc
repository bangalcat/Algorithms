#include <iostream>
#include <cmath>

using namespace std;

#define MAX_D 17    // log(N)
#define MAX_N 100000    // 가능 범위

int st_min[MAX_N+1][MAX_D+1];
int st_max[MAX_N+1][MAX_D+1];

int main()
{
    int N, Q;
    cin >> N;
    int arr[MAX_N+1];
    for(int i=0;i<N;++i) {
        cin >> st_min[i][0];
        st_max[i][0] = st_min[i][0];
    }
    for(int j=1;j<=MAX_D;++j) {
        for(int i=0;i + (1 << j) <= N;++i) {
            st_max[i][j] = max(st_max[i][j-1], st_max[i + (1<<(j-1))][j-1]);
            st_min[i][j] = min(st_min[i][j-1], st_min[i + (1<<(j-1))][j-1]);
        }
    }
    cin >> Q;
    for(int i=0;i<Q;++i) {
        // 3 구간 혹은 2 구간 으로 나눈다.
        // 2개 구간은 뒤늦게 불붙는 구간, 1개 구간은 먼저 불타는 구간
        // 2개 구간에 대해 최댓값, 1개 구간에 대해 최솟값, 최댓값 구하기
        int l1=0, r1, l2, r2, l3, r3=N-1;
        int max1=0, max2=0, max3=0;
        cin >> l2 >> r2;
        r1 = l2-1;
        l3 = r2+1;
        if(l1 <= r1){
            int j1 = log2(r1 - l1 + 1);
            max1 = max(st_max[l1][j1], st_max[r1 - (1<<j1) + 1][j1]);
        }
        int j2 = log2(r2 - l2 + 1);
        int min2 = min(st_min[l2][j2], st_min[r2 - (1<<j2)+1][j2]);
        max2 = max(st_max[l2][j2], st_max[r2 - (1<<j2) + 1][j2]);
        if(l3 <= r3){
            int j3 = log2(r3 - l3 + 1);
            max3 = max(st_max[l3][j3], st_max[r3 - (1<<j3) + 1][j3]);
        }
        double ret = max(max1 + min2, max3 + min2);
        // printf("%d %d %d ", max1, max3, min2);
        ret = max(ret, (max2 + min2) / 2.0);
        printf("%.1f\n", ret);
    }

    return 0;
}