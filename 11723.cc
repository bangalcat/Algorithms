#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int m; cin >> m;
    int S=0;
    for(int i=0; i<m; ++i) {
        string op; cin >> op;
        int x;
        if(op == "add"){
            cin >> x;
            S |= (1<<x);
        } else if(op == "check"){
            cin >> x;
            cout << ((S & (1<<x))>0) << '\n';
        } else if(op == "remove"){
            cin >> x;
            S &= ~(1<<x);
        } else if(op == "toggle"){
            cin >> x;
            S ^= (1<<x);
        } else if(op == "all"){
#define ALL 21
            S = (1<<ALL)-1;
        } else if(op == "empty"){
            S = 0;
        }
    }
    return 0;
}