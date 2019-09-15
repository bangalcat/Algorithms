#include <iostream>
#include <cstring>

using namespace std;

int n = -1;
int m = -1;

int cal[5001];
int money[5001];
int cache[10001];

int fun(int remain) {
    int &ret = cache[remain];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0;i<n;++i) {
        if(remain - money[i] >= 0){
            ret = max(ret, cal[i] + fun(remain - money[i]));
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(true) {
        memset(cache,-1,sizeof(cache));
        double f;
        cin >> n >> f;
        m = f * 100;
        if(n == 0) break;
        for(int i=0;i<n;++i) {
            int a;
            double t;
            cin >> a >> t;
            cal[i] = a;
            money[i] = t * 100;
        }

        cout << fun(m) << '\n';
    }
    return 0;
}