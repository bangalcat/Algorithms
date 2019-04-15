/* 
    문제이름 : 찾기
    KMP 기초
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
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
vector<int> kmp_find(const string &t, const string &s){
    vector<int> ans;
    vector<int> pi = get_pi(s);
    int n=t.size(), m = s.size(), matched = 0;
    for(int i=0 ; i < n ; i++){
        while(matched > 0 && t[i] != s[matched])
            matched = pi[matched-1];
        if(t[i] == s[matched]){
            if(matched == m-1){
                ans.push_back(i-m+1);
                matched = pi[matched];
            }else
                matched++;
        }
    }
    return ans;
}

int main(){
    string t,s;
    getline(cin,t);
    getline(cin,s);
    auto matched = kmp_find(t,s);
    cout << (int)matched.size() << '\n';
    for(auto e : matched)
        printf("%d ",e+1);
    return 0;
}
