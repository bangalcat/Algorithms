#include <iostream>

using namespace std;

#define MAX_D 31
#define MAX_N 100000

int st[MAX_N + 1][MAX_D + 1];

int main()
{
    int n, m, k;
    cin >> n >> k >> m;
    int arr[MAX_N+1];
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    for(int i=1;i<=k;++i) {
        cin >> st[i][0];
    }
    for(int j=1; j < MAX_D; ++j) {
        for(int i=1; i <= k; ++i){
            st[i][j] = st[st[i][j-1]][j-1];
        }
    }
    for(int i=0;i<n;++i) {
        int x = arr[i];
        // printf("%d ", x);
        int l = 1;
        int r = m-1;
        for(int j=MAX_D-1;j >= 0; --j){
            if(1<<j <= r - l + 1){
                x = st[x][j];
                // printf("(j, st[x][j]) : %d %d\n", j, x);
                r -= 1 << j;
            }
        }
        printf("%d ", x);
    }
    
    return 0;
}