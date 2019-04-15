/*
    문제 이름 : 에디터
    iterator의 특성을 잘 파악하고 있어야 했던 문제
    예를 들어 list의 iterator는 +1이나 -1같은 연산이 불가능
    erase()한 결과를 받으면 삭제한 다음 녀석의 포인터가 반환
*/
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
