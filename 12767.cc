#include<iostream>
#include<vector>
using namespace std;

const int LIMIT = 3000000;

int insert_tree(vector<int> &V, int a){
    int i=0;
    while(V[i]!=0){
        if(V[i] > a)
            i = i*2+1;
        else
            i = i*2+2;
    }
    V[i] = a;
}
int main(){
    int n, k; cin >> n >> k;
    vector<vector<int>> treebox;
    for(int i=0; i<n ; i++){
        vector<int> t(1<<k|1,0);
        int a = 0;
        for(int j=0; j<k; j++){
            cin >> a;
            insert_tree(t,a);
        }
        int diffCnt = 0;
        if(treebox.empty()) treebox.push_back(t);
        else{
            for(auto v : treebox){
                for(int j=0,len=t.size();j<len;j++){
                    if((v[j] && !t[j]) || (!v[j] && t[j])) {
                        diffCnt++;
                        break;
                    }
                }
            }
            if(diffCnt == treebox.size()) treebox.push_back(t);
        }
    }
    cout << treebox.size();
    return 0;
}