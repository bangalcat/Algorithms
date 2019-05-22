#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    vector<long long> pmod(n+1,0);
    vector<long long> modCnt(m,0);
    modCnt[0]++;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        pmod[i+1] = (pmod[i] + a) % m;
        modCnt[pmod[i+1]]++;
    }
    long long ans = 0;
    for(int i=0;i<m;++i){
        if(modCnt[i] > 0)
            ans += (modCnt[i] * (modCnt[i]-1)) / 2;
    }
    cout << ans;
    return 0;
}