#include <iostream>

using namespace std;

int main()
{
    int N, Q; cin >> N >> Q;
    int pxor[1000001] = {0};
    for(int i=0;i<N;++i){
        int a; cin >> a;
        pxor[i+1] = pxor[i] ^ a;
    }
    int ans=0;
    for(int i=0;i<Q;++i){
        int s, e; cin >> s >> e;
        ans ^= pxor[e] ^ pxor[s-1];
    }
    cout << ans;
    return 0;
}