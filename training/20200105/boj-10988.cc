#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int i = 0;
    for(;s[i]==s[s.size()-1-i]&&i<s.size()/2;++i){}
    if(i == s.size()/2)
        cout << 1;
    else 
        cout << 0;
    return 0;
}