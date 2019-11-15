#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> r;
vector<int> e;

int find_set(int u) {
    return u == parent[u] ? u : parent[u] = find_set(parent[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u != v) {
        if(r[u] < r[v])
            swap(u, v);
        parent[u] = v;
        if(r[u] == r[v])
            r[u]++;
    }
}

int n, q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    vector<pair<pair<int,int>,int>> queries;
    vector<int> colors(n, 0);
    parent.assign(n+1, 0);
    for(int i=0;i<n+1;++i)
        parent[i] = i;
    for(int i=0;i<q;++i) {
        int l, r, c;
        cin >> l >> r >> c;
        queries.push_back({{l-1, r-1},c});
    }
    for(int i=q-1; i>= 0; --i){
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        int c = queries[i].second;
        for(int v = find_set(l); v <= r;v = find_set(v)) {
            colors[v] = c;
            parent[v] = v + 1;
        }
    }
    for(int i=0;i<n;++i) {
        cout << colors[i] << '\n';
    }
    return 0;
}