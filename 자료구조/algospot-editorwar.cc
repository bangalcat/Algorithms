#include <iostream>
#include <vector>

using namespace std;

struct BitpartUnionFind{
    vector<int> parent, rank, enemy, size;
    BitpartUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1){
        for(int i=0;i<n;++i)
            parent[i] = i;
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v){
        //u나 v가 공집합인 경우 나머지 하나를 반환한다.
        if(u == -1 || v == -1) return max(u, v);
        u = find(u); v = find(v);
        if(u == v) return u;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        size[v] += size[u];
        if(rank[u] == rank[v]) ++rank[v];
        return v;
    }
    bool dis(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        // 적의 적은 나의 동지
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        //a와 b는 merge 후 루트
        enemy[a] = b; enemy[b] = a;
        return true;
    }
    bool ack(int u, int v){
        u = find(u); v = find(v);
        if(enemy[u] == v) return false;
        // 동지의 적은 적
        int a = merge(u, v), b = merge(enemy[v], enemy[u]);
        //a와 b는 merge 후 루트
        enemy[a] = b; 
        if(b != -1) enemy[b] = a;
        return true;
    }
};
int n,m;
int maxParty(const BitpartUnionFind& buf){
    int ret = 0;
    for(int node = 0; node < n; ++node){
        if(buf.parent[node] == node){
            int enemy = buf.enemy[node];
            //같은 모임 쌍을 두번 세지 않기 위해, enemy < node 인 경우만 센다?
            if(enemy > node) continue;
            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
            //둘 중 더 큰 집합 더하기
            ret += max(mySize, enemySize);
        }
    }
    return ret;
}


int main()
{
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        BitpartUnionFind party(n);
        bool contrad = false;
        int num=0;
        for(int i=0;i<m;++i){
            string type;
            int a, b; 
            cin >> type >> a >> b;
            if(type == "ACK")
                contrad = !party.ack(a, b);
            else
                contrad = !party.dis(a, b);
            
            if(contrad && num == 0) {
                num = i+1;
            }
        }
        if(num != 0){
            cout << "CONTRADICTION AT " << num << '\n';
        }else
            cout << "MAX PARTY SIZE IS " << maxParty(party) << '\n';
    }

    return 0;
}
