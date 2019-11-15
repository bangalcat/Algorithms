#include <iostream>
#include <map>

using namespace std;

#define MAX_D 31
#define MAX_N 100000

int st[MAX_N+1][MAX_D+1];
int arr[MAX_N];

int gcd(int a, int b){
    return b>0?gcd(b, a%b):a;
}

int main()
{
    int N, Q; cin >> N;
    for(int i=0;i<N;++i) {
        cin >> arr[i];
        st[i][0] = arr[i];
    }
    // build table
    for(int j=1;j<MAX_D;++j) {
        for(int i=0;i + (1<<j) <= N; ++i){
            st[i][j] = gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    // calc log
    int log[MAX_N + 1];
    log[1] = 0;
    for(int i=2; i<= MAX_N; ++i)
        log[i] = log[i/2] + 1;
    map<long long, long long> cache;
    // build map
    for(int l=0; l < N; ++l) {
        int r = l;
        int val = arr[l]; // val은 fix된 왼쪽값
        while(r < N) { // fix left one and look right until end
            int k = r;
            for(int j = log[r+1]; j >= 0; --j){
                // 오른쪽 남은 개수가 2^j이상이고 gcd(고정값, 2^j번째 gcd값) == 고정값
                // 즉 k번째 값의 gcd가 고정값의 배수일때 k를 2^j - 1만큼 옮긴다.
                if(N - k >= (1 << j) && gcd(val, st[k][j]) == val)
                    k = k + (1 << j) - 1;
            }
            if(cache.count(val)) // 개수 존재한다면
                cache[val] += (k - r + 1);
            else
                cache[val] = k - r + 1;
            r = k + 1; // k + 1까지 옮긴다.
            val = gcd(val, arr[r]);
        }
    }

    cin >> Q;
    while(Q--) {
        int x;
        cin >> x;
        cout << cache[x] << '\n';
    }
    return 0;
}