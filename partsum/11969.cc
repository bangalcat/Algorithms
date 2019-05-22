#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    int psum[3][100001] = {0};
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        a--;
        for(int t=0;t<3;++t)
            if(t==a)
                psum[t][i+1] = psum[t][i] + 1;
            else psum[t][i+1] = psum[t][i];
    }
    for(int i=0;i<q;++i){
        int a,b; cin >> a >> b;
        cout << psum[0][b] - psum[0][a-1] << ' ' << psum[1][b] - psum[1][a-1] << ' ' << psum[2][b] - psum[2][a-1] << '\n';
    }
    return 0;
}