/**
 * 모든 length k subsequence를 찾는 문제
 * k+1개의 fenwiktree 이용. fenwiktree[k][x]는 끝 숫자가 x로 끝나는 
 * length k의 subsequence의 개수
 * 
 */

#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll K = 13;
const ll N = 1e5 + 10;

ll fentree[K][N];
ll n, k, arr[N], ans;

ll query(ll id, ll x) {
    ll ret = 0;
    for(; x>0; x-=x&-x)
        ret += fentree[id][x];
    return ret;
}

ll update(ll id, ll x, ll num) {
    for(;x<N;x+=x&-x)
        fentree[id][x] += num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    if(k==0)
        return cout << n, 0;
    for(int i=0; i<n; ++i) {
        int a; 
        cin >> a;
        // k-1번째 a로 끝나는 수의 개수가 k번째 a로 끝나는 수의 개수에 더해진다
        for(ll j=0, x=1; j<k; j++) {
            ll ex = query(j, a);
            update(j, a, x);
            x = ex;
            if(j == k - 1)
                ans += ex;
        }
    }
    cout << ans;
    return 0;
}