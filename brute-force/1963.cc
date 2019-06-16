#include <bits/stdc++.h>

using namespace std;

bool erat[10000] = {0};

void eratones(){
    for(int i=2;i<=100;++i)
        if(!erat[i]) 
            for(int j=i*i;j<10000;j+=i)
                erat[j] = true;
}

int main(){
    int T; cin >> T;
    eratones();
    while(T--) {
        string src, trg;
        cin >> src >> trg;
        bool checked[10000]={0};
        int ans = 9999;
        function<void()> solve = [&](){
            queue<pair<int, string>> que;
            que.push({0, src});
            checked[atoi(src.c_str())] = true;
            while(!que.empty()){
                auto curr = que.front();
                que.pop();
                string p = curr.second;
                if(curr.first >= ans) continue;
                if(p == trg) {
                    ans = min(ans, curr.first);
                    return;
                }
                for(auto& c : p){
                    char prev = c;
                    for(char i='0';i<='9';++i){
                        if(prev != i){
                            c = i;
                            int n = atoi(p.c_str());
                            if(n >= 1000  && !checked[n] && !erat[n]){
                                checked[n] = true;
                                que.push({curr.first + 1,p});
                            }
                            c = prev;
                        }
                    }
                }
            }
        };
        if(src == trg){
            cout << 0 << endl;
        }else{
            solve();
            if(ans == 9999)
                cout << "Impossible" << endl;
            else
                cout << ans << endl;
        }
    }
    return 0;
}