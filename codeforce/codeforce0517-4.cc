#include <bits/stdc++.h>

using namespace std;

int main(){
    int q; cin >> q;
    for(int i=0;i<q;++i){
        long long a, b, m;
        cin >> a >> b >> m;
        vector<long long> arr;
        arr.push_back(a);
        long long next = a;
        while(next < b){
            
        }
        if(next > b) cout << -1;
        else
        {
            for(auto t : arr)
                cout << t << ' ';
        }
        cout << endl;
    }
    return 0;
}