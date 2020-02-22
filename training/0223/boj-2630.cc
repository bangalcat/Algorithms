#include <iostream>
#include <functional>

using namespace std;

int board[150][150];

int main()
{
    int n; cin >> n;
    for(int i=0; i<n ;++i) {
        for(int j=0; j<n; ++j) {
            cin >> board[i][j];
        }
    }
    int dr[4] = {0, 1, 0, 1}, dc[4] = {0, 0, 1, 1};
    function<pair<int,int>(int,int,int)> func = [&](int r, int c, int size) {
        int wc = 0, bc = 0;
        if(size == 1){
            if(board[r][c]) bc += 1;
            else wc += 1;
        } else {
            int hsize = size / 2;
            for(int i=0;i<4;++i) {
                auto t = func(r+dr[i] * hsize, c+dc[i] * hsize, hsize);
                wc += t.first;
                bc += t.second;
            }
            if(wc == 4 and bc == 0) wc = 1;
            if(bc == 4 and wc == 0) bc = 1;
        }
        return make_pair(wc, bc);
    };
    auto ret = func(0, 0, n);
    cout << ret.first << '\n' << ret.second;
    return 0;
}