#include <iostream>
#include <cmath>

using namespace std;

// 제곱 ㄴㄴ수

int solve(long long mn, long long mx){
    int end = sqrt(mx);
    bool check[1000001] = {0};
    for(int i=2;i<=end;++i) {
        long long ss = i*i;
        long long start = ((mn - 1) / ss + 1) * ss;
        for(long long a = start; a <= mx; a += ss)
            check[a - mn] = true;
    }
    int cnt = 0;
    for(int i=0;i< (mx - mn + 1); ++i)
        if(check[i]) cnt++;
    return mx - mn - cnt + 1;
}

int main()
{
    long long mn, mx;
    cin >> mn >>  mx;
    cout << solve(mn, mx);
    return 0;
}