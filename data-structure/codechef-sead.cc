#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_D 17    // log(N)
#define MAX_N 100000    // 가능 범위
#define INF 987654321

int st[MAX_N+1][MAX_D+1];
int ind[MAX_N+1][MAX_D+1];

int interval[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, Q;
    cin >> N;
    vector<int> arr(N+1,0);
    for(int i=1;i<=N;++i) {
        cin >> arr[i];
        st[i-1][0] = arr[i] - arr[i-1];
    }
    for(int j=1;j<=MAX_D;++j) {
        for(int i=0;i + (1 << j) <= N;++i) {
            st[i][j] = max(st[i][j-1], st[i + (1<<(j-1))][j-1]);
        }
    }
    cin >> Q;
    // t보다 작거나 같은 마지막 위치 p를 찾는다.
    // 1~p에서 간격이 d보다 큰 위치 k를 찾는다.
    // k가 시작점이다
    for(int i=0;i<Q;++i) {
        int t, d;
        cin >> t >> d;
        int p = upper_bound(arr.begin(), arr.end(), t) - arr.begin() - 1;
        int k_pos=p, k;
        // printf("%d |", p);
        int l = 1;
        int r = p;
        while(l < r){ // 이분탐색으로 찾아보자
            int m = (l + r) / 2;
        // for(int m=1; m < p;++m){ // 간격이 d보다 큰것이 없는 최소의 m을 찾는다.
            int j = log2(p - m); // 간격은 전체개수가 1적다 r = p - 1
            k = max(st[m][j], st[p - (1<<j)][j]);
            // printf("%d %d | ", st[m][j], st[p - (1<<j)][j]);
            if(k <= d){
                r = m;
            }else{
                l = m + 1;
            }
        }
        cout << l << '\n';
    }

    return 0;
}