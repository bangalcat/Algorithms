#include <iostream>

using namespace std;

#define MAX 19
#define MAX_N 500001
int st[MAX_N][MAX] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, q;
    cin >> m;
    for(int i=1;i<=m;++i){
        cin >> st[i][0];
    }
    for(int j=1;j<MAX;++j){
        for(int i=1;i<=m;++i)
            st[i][j] = st[st[i][j-1]][j-1];
    }
    cin >> q;
    for(int i=0;i<q;++i){
        int n, x;
        cin >> n >> x;
        for(int j=MAX-1; j >= 0; --j) {
            if(n >= 1 << j){
                x = st[x][j];
                n -= 1 << j;
            }
        }
        cout << x << '\n';
    }
    return 0;
}