#include <iostream>
#include <vector>
using namespace std;

//노드들은 조상 노드를 가리키도록
// 최고 조상이 다른 조상에 포함되어있으면 
// 두 점 주어졌을 때, 1.한 점의 조상이 다른 점의 조상에 포함
// 2. two different ancestor node
// 3. two same ancestor node -> ignore
// union 시 ancestor node의 count 합계

int find_ancestor(vector<pair<int,int>> &tree, int node){
    return tree[node].first==node? node : find_ancestor(tree,tree[node].first);
}

int main()
{
    int n; cin >> n;
    int m; cin >> m;
    vector<pair<int, int>> tree(n+1);
    for(int i=1; i<n+1; i++) tree[i] = {i,1};
    while(m--){
        int a, b;
        cin >> a >> b;
        int ap = find_ancestor(tree, a);
        int bp = find_ancestor(tree, b);
            
        if(ap < bp){
            tree[bp].first = ap;
            tree[ap].second += tree[bp].second;
        }else if(ap > bp){
            tree[ap].first = bp;
            tree[bp].second += tree[ap].second;
        }
    }
    cout << tree[1].second-1;

    return 0;
}
