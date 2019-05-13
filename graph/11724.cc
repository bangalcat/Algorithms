/*
    백준 : 연결 요소의 개수
    무방향 그래프에서 컴포넌트 개수 세기
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> root;
int find(int u){
    return u == root[u] ? u : root[u] = find(root[u]);
}
int merge(int u,int v){
    u = find(u), v = find(v);
    return u == v ? u : root[v] = u;
}

int main(){
    int n, m;
    cin >> n >> m;
    root = vector<int>(n);
    for(int i=0;i<n;++i)
        root[i] = i;
    for(int i=0;i<m;++i){
        int u, v;
        cin >> u >> v;
        u--, v--;
        merge(u, v);
    }
    vector<bool> checked(n,0);
    int ans = 0;
    for(int i=0;i<n;++i){
        if(!checked[find(i)]){
            checked[find(i)] = true;
            ans++;
        }
    }
    
    cout << ans;

    return 0;
}
/*
// dfs 이용
#include <cstdio>
int n, m, a, b, k;
bool c[1001], d[1001][1001];
void dfs(int a)
{
    for (int i = 1; i <= n; i++)
        if (!c[i] && d[a][i])
        {
            c[i] = true;
            dfs(i);
        }
}
int main()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        scanf("%d %d", &a, &b);
        d[a][b] = d[b][a] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!c[i])
        {
            dfs(i);
            k++;
        }
    printf("%d\n", k);
}
*/