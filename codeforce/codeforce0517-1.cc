#include <iostream>

using namespace std;

int comb2(int n){
    if(n < 2) return 0;
    return n * (n-1) / 2;
}

int main()
{
    int n; cin >> n;
    int cnt[26] = {0};
    for(int i=0; i< n;++i){
        string s; cin >> s;
        cnt[s[0]-'a']++;
    }
    int ans = 0;
    for(int i=0;i<26;++i){
        int t = cnt[i];
        if(t!= 1 && t%2){
            ans += comb2(t/2);
            ans += comb2(t/2+1);
        }else{
            ans += comb2(t/2) * 2;
        }
    }
    cout << ans;
    return 0;
}