#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int p=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='-' && p>0) p--;
        else if(s[i]=='+') p++;
    }
    cout << p;
    return 0;
}