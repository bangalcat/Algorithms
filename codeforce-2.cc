
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n; cin >> n;
    set<int> s;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        s.insert(a);
    }
    if(s.size() > 3) cout << -1;
    if(s.size() == 3){
        int lo = *s.begin();
        int hi = *(--s.end());
        if((lo+hi)%2==0 && (lo+hi)/2 == *(++s.begin()))
            cout << (hi-lo)/2;
        else cout << -1;
    }else if(s.size() == 2){
        int ans = *(--s.end()) - *(s.begin());
        if(ans%2==0) ans/=2; 
        cout << ans;
    }else
    {
        cout << 0;
    }
    
    return 0;
}