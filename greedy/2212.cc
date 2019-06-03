

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> pos;
    multiset<int> inters;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        pos.insert(a);
    }
    int prev=987654321;
    for(auto p : pos){
        if(prev != 987654321){
            inters.insert(p - prev);
        }
        prev = p;
    }
    // cout << inters.size() << endl;
    int ans = (*pos.rbegin()) - (*pos.begin());
    // cout << ans << endl;
    for(auto s = inters.rbegin();s != inters.rend();s++){
        if(--k==0) break;
        ans -= *s;
    }
    cout << ans << endl;
    return 0;
}