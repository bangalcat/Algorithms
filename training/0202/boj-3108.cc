// 로고
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> board(1010, vector<int>(1010, 9999));
    int count = 0;
    board[500][500] = -1;
    for(int i=0;i<n;++i) {
        bool over_flag = false;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 500;
        x2 += 500;
        y1 += 500;
        y2 += 500;
        // line 1 & 3
        for(int p = x1; p <= x2; ++p){
            if(board[p][y1] < i || board[p][y2] < i)
                over_flag = true;
            board[p][y1] = board[p][y2] = i;
        }
        for(int p = y1; p <= y2; ++p){
            if(board[x1][p] < i || board[x2][p] < i)
                over_flag = true;
            board[x1][p] = board[x2][p] = i;
        }
        if(!over_flag)
            count += 1;
    }
    // if(board[500][500] < 9999) count -= 1;
    cout << count;
    return 0;
}