/**
 *  codeforce - little artem and time machine
 *  여러 풀이 방법 존재
 *  sqrt decomposition 등
 *  fenwiktree
 *  헷갈렸던 점 : 답변 순서보다 시간 순서가 먼저인가? 아니다.
 *  답변 순서대로 보면서 시간 순서를 고려
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class FenwikTree {
    vector<int> tree;
    int n;
    public:
    FenwikTree(int size1) {
        n = size1 + 1;
        tree.assign(n, 0);
    }

    void add(int idx, int d) {
        for(++idx; idx < n; idx+=idx&-idx)
            tree[idx] += d;
    }

    int point_query(int idx) {
        int ret = 0;
        for(++idx; idx > 0; idx-=idx&-idx)
            ret += tree[idx];
        return ret;
    }
};
// SQRT Decopression? 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    map<int, vector<vector<int>>> queries;
    set<int> times;
    set<int> numbers;
    int q_idx = 0;
    map<int, int> shouldAnswer;
    for(int i=0;i<q;++i) {
        int a, t, x;
        cin >> a >> t >> x;
        queries[x].push_back({a, t, q_idx});
        times.insert(t);
        numbers.insert(x);
        if(a == 3) q_idx++, shouldAnswer[x] = true;
    }
    // compression
    map<int, int> timedict;
    int id1 = 0;
    for(auto a : times){
        timedict[a] = id1++;
    }
    vector<int> ans(q_idx, -1);
    // process each number
    for(auto x : numbers) {
        if(shouldAnswer.find(x) == shouldAnswer.end()) continue;
        FenwikTree ft(100000);
        auto v = queries[x]; // query for number x
        for(int i=0; i < v.size(); ++i) {
            if(v[i][0] == 1) {
                ft.add(timedict[v[i][1]], 1);
            }else if(v[i][0] == 2) {
                ft.add(timedict[v[i][1]], -1);
            }else {
                ans[v[i][2]] = ft.point_query(timedict[v[i][1]]);
            }
        }
    }
    for(auto a : ans)
        cout << a << '\n';
    return 0;
}