/*
    백준 : HAN
    사이클 문제라 했지만 나머지 활용해서 시뮬레이션 돌림
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int Q; cin >> Q;
    int prev = 0, pos=25, n, plus, r;
    string s;
    vector<int> alpha_cnts(26,0);
    int cw = 1;
    for(int i=0; i < Q; ++i){
        cin >> s >> n;
        int diff = n - prev;
        r = diff % 26;
        plus = diff / 26;
        if(plus > 0) for(int i=0;i<26;++i)
            alpha_cnts[i] += plus;
        pos += cw;
        for(int i=0; i < r; ++i){
            int np = (pos + cw * i + 26) % 26;
            alpha_cnts[np]++;
        }
        pos = (pos + cw * (r-1) + 26) % 26;

        if(s[0] == 'U'){
            char x;
            cin >> x;
            cout << alpha_cnts[x-'a'] << '\n';
        }else
            cw*=-1;
        prev = n;
    }
    
    return 0;
}