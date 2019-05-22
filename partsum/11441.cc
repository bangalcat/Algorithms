#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    vector<int> psum(n+1,0);
    for(int i=0;i<n;++i){
        int a; cin >> a;
        psum[i+1] = psum[i] + a;
    }
    int m; cin >> m;
    for(int i=0;i<m; ++i){
        int a, b; cin >> a >> b;
        cout << psum[b] - psum[a-1] << '\n';
    }
    
    return 0;
}