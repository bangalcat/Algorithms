#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
    광고 - 전광판 문제
*/
vector<int> get_pi(const string &s){
    int m = s.size();
    int j=0;
    vector<int> pi(m,0);
    for(int i=1; i < m ; i++){
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            pi[i] = ++j;
    }
    return pi;
}
int solve(const string& s, int L){
    int ret = L;
    if(ret == 1)
        return ret;
        
    vector<int> pi = get_pi(s);
    int i=L-1;
    
    ret = L - pi[L-1];
        
    return ret;
}
int main(){
    int L; cin >> L;
    string s; cin >> s;
    cout << solve(s, L);
    return 0;
}