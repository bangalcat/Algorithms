#include <iostream>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

int ctnz(int n){
    if(n==0) return 0;
    return n%2 + ctnz(n>>1);
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n, k, m, l;
        cin >> n >> k >> m >> l;
        vector<int> precourse(n+1,0);
        for(int i=0;i<n;++i){
            int c; cin >> c;
            while(c--){
                int b; cin >> b;
                precourse[i] |= (1<<b);
            }
        }
        int courses[11];
        vector<int> semester(m);
        int cache[11][1<<13]={0};
        memset(cache,-1,sizeof(cache));
        for(int i=0;i<m;++i){
            int c; cin >> c;
            int t=0;
            for(int j=0; j<c; ++j){
                int a; cin >> a;
                t |= (1 << a);
            }
            courses[i] = t;
        }
        #define INF 987654321
        function<int(int, int)> graduate = [&](int sem, int taken){
            if(ctnz(taken)>=k) return 0;
            if(sem == m) return INF;
            int& ret = cache[sem][taken];
            if(ret != -1) return ret;
            ret = INF;
            int cantake = (courses[sem] & ~taken);
            for(int i=0; i < n;++i) {
                if((cantake & (1 << i)) && (taken & precourse[i]) != precourse[i])
                    cantake &= ~(1 << i);
            }
            for(int subset = cantake; subset; subset = (subset-1)&cantake){
                if(ctnz(subset) > l) continue;
                ret = min(ret, graduate(sem+1,taken|subset)+1);
            }
            ret = min(ret, graduate(sem+1, taken));
            return ret;
        };
        int ans = graduate(0, 0);
        if(ans == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}