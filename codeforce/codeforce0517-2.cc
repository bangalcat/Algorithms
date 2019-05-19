#include <bits/stdc++.h>

using namespace std;


vector<string> correct = {
    "aeiou",
    "eaoui",
    "iouea",
    "ouaie",
    "uieao"
};

int main(){
    int k; cin >> k;
    int n, m;
    vector<string> ret; 

    auto solve = [&](){
        ret = vector<string>(n,string(m,'t'));
        for(int i=0;i<n;++i){
            for(int j=0;j<5;++j){
                if(i < 5 && j < 5){
                    ret[i][j] = correct[i][j];
                }else
                {
                    ret[i][j] = correct[0][j];
                }
            }
        }
        for(int j=5;j<m;++j){
            for(int i=0;i<5;++i)
                ret[i][j] = correct[i][0];
        }
        for(auto s : ret)
            cout << s;
    };

    for(n=0;n<k;++n){
        if(n < 5) continue;
        if(k / n < 5) continue;
        if(k%n == 0){
            m = k / n;
            solve();
            return 0;
        }
    }
    cout << -1;
    return 0;
}