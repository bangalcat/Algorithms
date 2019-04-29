#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int R, C;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        string s = "IMPOSSIBLE";
        cin >> R >> C;
        vector<pair<int, int>> g[20][20];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                for (int ii = 0; ii < R; ii++)
                {
                    for (int jj = 0; jj < C; jj++)
                    {
                        if (i != ii && j != jj && i - j != ii - jj && i + j != ii + jj)
                        {
                            g[i][j].push_back({ii, jj});
                        }
                    }
                }
            }
        }
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                random_shuffle(g[i][j].begin(), g[i][j].end());
        // if(R > C) {
        //     isSwap = true;
        //     swap(R, C); // to make solvable by using divide and conquer
        // }
        //R과 C는 2이상
        //R이 2이면 C는 5 이상이어야함
        //R이 3이면 C는 4 이상
        //R이 4이상이면? 알고리즘 돌리기
        //사실 test set 1에서 남은 케이스는 2x5, 3x4, 3x5, 4x5
        //knights move는 5x5 이상에서 다음 3가지 경우 제외하고 답이 존재
        // 1. r, c 둘 다 홀수
        // 2. r = 1, 2 or 4 (r <= c)
        // 3. r = 3 and c = 1, 2, 3, 5, or 6
        bool isFindAns = false;
        vector<vector<bool>> was(R, vector<bool>(C, false));
        vector<int> curR(400, -1);
        vector<int> curC(400, -1);
        function<void(int, int, int)> go = [&](int depth, int r, int c) {
            if (isFindAns)
                return;
            curR[depth] = r;
            curC[depth] = c;
            was[r][c] = true;
            if (depth == R * C - 1)
            {
                isFindAns = true;
                return;
            }
            for (auto p : g[r][c])
            {
                if (!was[p.first][p.second])
                    go(depth + 1, p.first, p.second);
            }
            was[r][c] = false;
        };
        go(0, 0, 0);
        cout << "Case #" << t << ": ";
        if (!isFindAns)
            cout << "IMPOSSIBLE" << '\n';
        else
        {
            cout << "POSSIBLE" << '\n';
            for (int i = 0; i < R * C; ++i)
            {
                cout << curR[i]+1 << ' ' << curC[i]+1 << '\n';
            }
        }
    }
    return 0;
}