#include <bits/stdc++.h>

using namespace std;

string opers = "|&^";


char calculate(char a, char b, char op){
    if(b == 'x' || b == 'X') swap(a, b);
    if(op == '|'){
        if(b == '1') return '1';
        else if(b == '0') return a;
        else if(a == b) return a;
        else return '1';
    } else if(op == '&'){
        if(b == '0') return '0';
        else if(b == '1') return a;
        else if(b == a) return a;
        else return '0';
    } else if(op == '^'){
        if(b == '0') return a;
        else if(b == '1') return a == 'x'?'X':'x';
        else if(b == a) return '0';
        else return '1';
    }else{
        cerr << "error" << endl;
        return a;
    }
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        string eval, poste; 
        cin >> eval;
        stack<char> calc;
        for(auto c : eval) {
            if(c == '(')
                calc.push(c);
            else if(c == ')') {
                char p = ' ';
                while(p != '(') {
                    p = calc.top();
                    if(p != ')' && p != '(')
                        poste.push_back(p);
                    calc.pop();
                }
            }
            else if(opers.find(c) == string::npos){
                poste.push_back(c);
            }else{
                calc.push(c);
            }
        }
        while(!calc.empty()){
            poste.push_back(calc.top());
            calc.pop();
        }
        int ans = 0;
        for(auto c : poste){
            if(opers.find(c) == string::npos){
                calc.push(c);
            }else{
                char a = calc.top(); calc.pop();
                char b = calc.top(); calc.pop();
                calc.push(calculate(a,b,c));
            }
        }
        char ret = calc.top();
        if(ret == 'x' || ret == 'X') ans = 1; 

        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}