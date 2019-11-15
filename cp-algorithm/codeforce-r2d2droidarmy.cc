#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
const int MAX_N = 1e5;
const int MAX_M = 5;
const int MAX_D = 18;

int droids[MAX_N + 1][MAX_M + 1];
int st[MAX_M + 1][MAX_N + 1][MAX_D + 1];
int log[MAX_N + 1];
vector<int> ans;


void build() {
    for(int i=0;i<N;++i) {
        for(int j=0;j<M;++j) {
            st[j][i][0] = droids[i][j];
        }
    }
    for(int k=0; k<M; ++k)
        for(int j=1;j<MAX_D;++j) 
            for(int i=0;i + (1<<j) <= N; ++i)
                st[k][i][j] = max(st[k][i][j-1], st[k][i+(1<<(j-1))][j-1]);
    log[1] = 0;
    for(int i=2; i<= MAX_N; ++i)
        log[i] = log[i/2] + 1;
}

bool ok(int len) {
    vector<int> ret(M, 0);
    for(int i=0;i + len -1 < N;++i) {
        int sum = 0;
        int k = log[len];
        for(int j=0; j < M; ++j) {
            ret[j] = max(st[j][i][k], st[j][i+len - (1<<k)][k]);
            sum += ret[j];
        }
        if(sum <= K) {
            // printf("%d\n", len);
            ans = ret;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    ans = vector<int>(M,K/M);
    for(int i=0;i < N;++i) {
        for(int j=0;j<M;++j)
            cin >> droids[i][j];
    }
    build();
    int l = 0;
    int r = N;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ok(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    for(auto a : ans)
        printf("%d ", a);
    return 0;
}