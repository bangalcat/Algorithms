#include <iostream>

using namespace std;

double xpos[101], ypos[101], range[101];

void input(int n){
    for(int i=0;i<n;++i){
        cin >> xpos[i] >> ypos[i] >> range[i];
    }
}

void solve() {
    
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        input(n);
        solve();
    }
    return 0;
}