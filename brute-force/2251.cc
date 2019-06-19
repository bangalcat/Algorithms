#include <bits/stdc++.h>

using namespace std;

int A, B, C;
bool checked[201][201] = {0};
set<int> ret;

void pour(int a, int b, int c){
    if(checked[a][b])
        return;
    checked[a][b] = true;
    if(a == 0) ret.insert(c);
    // a -> b   
    if(a + b > B)
        pour(a + b - B, B, c);
    else 
        pour(0, a+b, c);
    
    // b -> a
    if(a + b > A)
        pour(A, a + b - A, c);
    else 
        pour(a+b, 0, c);

    // c -> a
    if(a + c > A)
        pour(A, b, a + c - A);
    else 
        pour(a+c, b, 0);
    // c -> b
    if(b + c > B)
        pour(a, B, b + c - B);
    else 
        pour(a, b + c, 0);
    // a->c b->c
    pour(0, b, a+c);
    pour(a, 0, b+c);
}

int main() {
    cin >> A >> B >> C;
    pour(0,0,C);
    for(auto p : ret)
        cout << p << ' ';
    return 0;
}