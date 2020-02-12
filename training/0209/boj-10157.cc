// 자리배정 - 수학적 시뮬레이션
#include <iostream>

using namespace std;

int main()
{
    int c, r, k;
    cin >> c >> r >> k;
    if (k > c * r)
        cout << 0;
    else {
        int cur_c = 1, cur_r = 1;  // 현재 좌표
        int cur_v = 1; // 좌석번호
        int col = c, row = r; // 현재 c, r 길이
        int temp = 0;
        // (1, 1) 에서 대각선 위로 한칸씩 올라갈때마다 2 * (c-1 + r-1) -1 만큼 더해진다
        while(k > (temp = cur_v + 2 * (col + row - 2) - 1)){
            cur_v = temp + 1;
            cur_c += 1, cur_r += 1;
            col -= 2;
            row -= 2;
        }
        auto func = [&](int& cur, bool rev, int val) {
            cur += (rev?-1:1) * val;
            cur_v += val;
        };
        // 4개 변 검사
        for(int d = 0; d < 4; ++d ) {
            int val = (d % 2 ? col - 1 : row - 1);
            if (k > cur_v + val) {
                func(d % 2 ? cur_c : cur_r, d >= 2, val);
            }else {
                func(d % 2 ? cur_c : cur_r, d >= 2, k - cur_v);
                break;
            }
        }
        cout << cur_c << ' ' << cur_r;
    }
    return 0;
}