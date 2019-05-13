
#include <bits/stdc++.h>

using namespace std;

const int MAX = 595;

int main(){
    int T, F;
    cin >> T >> F;

    for(int t=1;t<=T;++t){
        vector<int> pos[5];
        string ans ="";
        //1st 119 try
        for(int i=1;i<=MAX;i+=5){
            char a;
            cout << i << endl;
            cin >> a;
            pos[a-'A'].push_back(i);
        }
        int next;
        for(int i=0;i<5;++i){
            if(pos[i].size() != 24){
                ans += (i+'A');
                next = i;
                break;
            }
        }
        vector<int> pos2[5];
        //2nd 23 try
        for(int i=0;i<pos[next].size();++i){
            char a;
            cout << pos[next][i]+1 << endl;
            cin >> a;
            pos2[a-'A'].push_back(pos[next][i]+1);
        }
        for(int i=0;i<5;++i){
            if(pos2[i].size() != 0 && pos2[i].size() != 6){
                next = i;
                ans += (i+'A');
                break;
            }
        }
        //3rd 5 try
        vector<int> pos3[5];
        for(int i=0;i<pos2[next].size();++i){
            char a;
            cout << pos2[next][i]+1 << endl;
            cin >> a;
            pos3[a-'A'].push_back(pos2[next][i]+1);
        }
        for(int i=0;i<5;++i){
            if(pos3[i].size() != 0 && pos3[i].size() != 2){
                next = i;
                ans += (i+'A');
                break;
            }
        }
        //4th 1 try
        char a;
        cout << pos3[next][0]+1 << endl;
        cin >> a;
        bool exist[5]={0};
        for(auto c : ans)
            exist[c-'A'] = true;
        exist[a-'A'] = true;
        for(int i=0;i<5;++i)
            if(!exist[i])
                ans += (i+'A');
        ans += a;
        cout << ans << endl;
        string respon;
        cin >> respon;
        assert(respon=="Y");
    }
    
    return 0;
}