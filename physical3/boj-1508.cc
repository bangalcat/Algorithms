#include <bits/stdc++.h>

//백준 : 레이스

using namespace std;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> pos;
    for(int i=0;i<K;++i){
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());

    auto decision = [&](int len) {
        return true;
    };
    
    return 0;
}