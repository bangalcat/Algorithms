/*
    백준 : 트리의 가중치
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

const int DIV = 1000000007;

int main()
{
    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited(n,false);
    for(int i=0;i<n-1;++i){
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    #define w second
    #define v first
    long long D[100001] = {0};
    long long tot = 0;
    auto calc = [&](vector<long long>& arr){
        long long ret = 0;
        for(auto i : arr)
            ret += i;
        ret %= DIV;
        ret = (ret * ret) % DIV + DIV;
        long long subt=0;
        for(auto i : arr){
            subt += i*i;
            subt %= DIV;
        }
        ret -= subt;
        // if(ret < 0) cout << 'R' <<ret << endl;
        return ret%2?(ret+DIV)/2%DIV:ret/2 % DIV;
    };
    //트리 분할 탐색
    function<long long(int)> divConq = [&](int node) {
        long long ret=0;
        vector<long long> subtree_val;
        for(auto child : adj[node]){
            if(!visited[child.v]){
                visited[child.v] = true;
                long long c = divConq(child.v) % DIV;
                tot = (tot + c) % DIV;

                long long wc = (c+1)*child.w % DIV;
                subtree_val.push_back(wc);
                ret += wc;
                ret %= DIV;
            }
        }
        // if(tot < 0) cout << tot << endl;
        tot = (tot + calc(subtree_val)) % DIV;
        return ret % DIV;
    };
    visited[0] = true;
    tot += divConq(0);
    cout << tot%DIV << endl;
    return 0;

}

/*
    // 좋은 코드!!
 //acmicpc 1289; 트리의 가중치
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef long long ll;
const int MAX = 1e5;
int n, a, b, w;

vector<pair<int, int>> node[MAX + 1];
int ans;

int dfs(int cur, int parent);

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> w;

		node[a].push_back(make_pair(b, w));
		node[b].push_back(make_pair(a, w));
	}

	dfs(1, -1);
	cout << ans;

	return 0;
}

int dfs(int cur, int parent)
{
	int res = 1, part = 0;
	for (auto iter : node[cur]) {
		if (iter.first == parent) continue;
		int tmp = (ll)dfs(iter.first, cur) * iter.second % MOD;
		res = (res + (ll)tmp) % MOD;
		ans = (ans + (ll)tmp) % MOD;

		if (part != 0) {
			ans = (ans + part * (ll)tmp) % MOD;
		}
		part = (part + (ll)tmp) % MOD;
	}

	return res;
}
*/