#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() 
{
    int n, m; 
    cin >> n >> m;
    vector<int> seats(n+1, 0);
    vector<vector<int>> cache(n+1, vector<int>(2, 0));
    for (int i=0; i<m; ++i) {
        int a; cin >> a;
        seats[a-1] = 1;
    }
    // 현재 idx번재 seats까지 가짓수, b는 이전시트에서 현재 시트와 자리를 바꿨는가?
    function<int(int, int)> func = [&](int idx, int b) {
        if(idx == n-1)
            return 1;
        int& ret = cache[idx][b];

        if(ret != 0)
            return ret;

        if(b) {
            ret = func(idx+1, 0);
        } else if(seats[idx+1] || seats[idx]){
            ret = func(idx+1, 0);
        }else
            ret = func(idx+1, 1) + func(idx+1, 0);

        return ret;
    };

    cout << func(0, 0);

    return 0;
}