#include <iostream>
#include <queue>

using namespace std;

struct RNG{
    long long seed, mul, add;
    RNG(int seed, int mul, int add) {
        this->seed = seed;
        this->mul = mul;
        this->add = add;
    }
    long long next() {
        long long ret = seed;
        seed = (seed * mul + add) % 65536;
        return ret;
    }
};

class FenwikTree {
    vector<int> tree;
    int n;
    public:
    FenwikTree(int size) {
        n = size + 1;
        tree.assign(n, 0);
    }
    void update(int idx, int val) {
        for(++idx; idx < n; idx += idx & -idx){
            tree[idx] += val;
        }
    }
    void range_update(int l, int r, int val) {
        update(l, val);
        update(r + l, -val);
    }
    int sum(int idx) {
        int ret = 0;
        for(++idx; idx > 0; idx -= idx & -idx)
            ret += tree[idx];
        return ret;
    }
};

int main()
{
    int T = 0;
    cin >> T;
    while(T--) {
        int s, m, a, n, k;
        cin >> s >> m >> a >> n >> k;
        RNG rng(s, m, a);
        FenwikTree ft(65536);
        queue<int> que;
        // point update로 개수를 추가
        // range query와 이분탐색으로 k번째 수 찾기
        // N * log(65536)^2
        // 문제점 : idx에 0이 들어갈수도 있음. 0-base가 아님
        // 해결 : 입력은 0-base로 가정, 내부에서 1-base로 처리
        long long ret = 0;
        for(int i=0;i<n;++i) {
            que.push(rng.next());
            ft.update(que.back(), 1);
            if(i >= k - 1) {
                int lo = 0, hi = 65536;
                while(lo < hi) {
                    int mid = (lo + hi) / 2;
                    if(ft.sum(mid) >= (k+1)/2)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                // cout << "lo : " << lo << '\n';
                ret += lo;
                ft.update(que.front(), -1);
                que.pop();
            }
        }
        cout << ret << '\n';
    }
    return 0;
}