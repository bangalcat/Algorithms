#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999999;

struct Rank{
    int con[3];
};

class FenwikTree{
    vector<int> tree;
    int n;
    public:
    FenwikTree(int size) {
        n = size + 1;
        tree.assign(n, INF);
    }
    void update(int idx, int val) {
        for(++idx; idx < n; idx+=idx&-idx)
            tree[idx] = min(tree[idx], val);
    }
    int get(int idx) {
        int ret = INF;
        for(++idx; idx > 0; idx-=idx&-idx)
           ret = min(ret, tree[idx]);
        return ret;
    }
};

int main() 
{
    int n; cin >> n;
    Rank contest[n+1];
    for(int t=0;t<3;++t){
        for(int i=0;i<n;++i){
            int a; cin >> a;
            contest[a-1].con[t] = i;
        }
    }
    FenwikTree ft(n);
    sort(contest, contest + n, [&](const auto a, const auto b){
        return a.con[0] < b.con[0];
    });
    int ans = 0;
    for(int i=0;i<n;++i) {
        // 1번째 경기에서 나를 이긴놈들만 update되어있는 상태
        // 2번째 경기 나를 이긴놈중 3번째 경기에서 가장 앞선 랭크 구함
        int ret = ft.get(contest[i].con[1]); 
        // 그 결과가 3번째 경기에서 나보다 랭크 앞서면(숫자 낮으면)fail
        ans += (ret >= contest[i].con[2]); 
        // 업데이트
        ft.update(contest[i].con[1], contest[i].con[2]);
    }

    cout << ans;

    return 0;
}