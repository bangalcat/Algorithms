#include <iostream>
#include <vector>

using namespace std;

// 1블록 = 연속된 1 블록. 0과 1 toggle 가능
// disntinct한 1블록 개수

struct Node {
    int prefix=0, suffix=0; // 맨 앞과 뒤의 숫자
    int val=0, sum=0;
} tree[100000 * 4 + 1];

void build(int idx, int b, int e, const string& s) {
    if(b > e) return;
    if(b==e) {
        tree[idx].val = (s[b-1] == '1');
        tree[idx].suffix = tree[idx].prefix = tree[idx].sum = tree[idx].val;
        return;
    }
    int mid = (b + e) / 2;
    build(idx * 2, b, mid, s);
    build(idx * 2 + 1, mid + 1, e, s);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
    if(tree[idx*2].suffix && tree[idx*2+1].prefix)
        tree[idx].sum--;
    tree[idx].prefix = tree[idx*2].prefix;
    tree[idx].suffix = tree[idx*2+1].suffix;
}
// l부터 r까지의 update. 이 문제에서는 무조건 l==r임
void update(int idx, int b, int e, int l, int r) {
    if(b > e || l > e || r < b) return;
    if(b >= l && e <= r) { // b와 e가 일치해야함. 즉 leaf 의미
        tree[idx].val = 1 - tree[idx].val;
        tree[idx].sum = tree[idx].prefix = tree[idx].suffix = tree[idx].val;
        return;
    }
    int m = (b + e) / 2;
    update(idx*2, b, m, l, r);
    update(idx*2+1, m+1, e, l, r);
    tree[idx].sum = tree[idx*2].sum + tree[idx*2+1].sum;
    if(tree[idx*2].suffix && tree[idx*2+1].prefix)
        tree[idx].sum--;
    tree[idx].prefix = tree[idx*2].prefix;
    tree[idx].suffix = tree[idx*2+1].suffix;
}

Node query(int idx, int b, int e, int l, int r) {
    if(b > e || l > e || r < b) return tree[0];
    if(b >= l && e <= r){
        return tree[idx];
    }
    int m = (b + e) / 2;
    Node ln = query(idx*2, b, m, l, r);
    Node rn = query(idx*2+1, m+1, e, l, r);
    Node ret;
    ret.sum = ln.sum + rn.sum;
    if(ln.suffix && rn.prefix)
        ret.sum--;
    ret.prefix = ln.prefix;
    ret.suffix = rn.suffix;
    return ret;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    build(1, 1, n, s);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int x; cin >> x;
            update(1, 1, n, x, x);   
        }else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y).sum << '\n';
        }
    }
    return 0;
}