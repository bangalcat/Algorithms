#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        if(a == 0){
            if(pq.empty())
                cout << 0 << endl;
            else{
                cout << -pq.top().second << endl;
                pq.pop();
            }
        }else{
            pq.push({-abs(a), -a});
        }
    }
    return 0;
}