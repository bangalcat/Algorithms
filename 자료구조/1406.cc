#include <iostream>
#include <list>

using namespace std;

int main() {
    string s; cin >> s;
    int N; cin >> N;
    list<char> slist(s.begin(),s.end());
//    slist.push_back('\0');
    auto it = slist.end();
    while(N--){
        char c;
        char op; cin >> op;
        if(op == 'P'){
            cin >> c;
            slist.insert(it,c);
        }else if(op == 'L') {
            if(it != slist.begin())
                it--;
        }else if(op == 'D') {
            if(it != slist.end())
                it++;
        }else if(op == 'B') {
            if(it != slist.begin()){
                it--;
                it = slist.erase(it);
            }
        }
    }
    string k(slist.begin(),slist.end());
    cout << k;
    return 0;
}
