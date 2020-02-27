#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fi first
#define se second

int dr[4] = {1, 0 , -1, 0}, dc[4] = {0, 1, 0, -1};

int main()
{
    int R, C;
    cin >> R >> C;
    vector<string> madang(R);
    for (int i = 0; i < R; ++i) {
        cin >> madang[i];
    }
    vector<vector<int>> visit(R, vector<int>(C, 0));
    auto isRange = [R, C] (int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    };
    auto bfs = [&](int sr, int sc) {
        int sheep_cnt = 0;
        int wolf_cnt = 0;
        queue<pair<int,int>> que;
        que.push({sr, sc});
        while(!que.empty()) {
            auto curr = que.front();
            que.pop();
            int r = curr.fi, c = curr.se;
            if(visit[r][c]) continue;
            visit[r][c] = 1;
            if(madang[r][c] == 'v')
                wolf_cnt += 1;
            else if(madang[r][c] == 'o')
                sheep_cnt += 1;
            else if(madang[r][c] == '#')
                continue;
            for(int d=0; d<4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if(isRange(nr, nc) && !visit[nr][nc]){
                    que.emplace(nr, nc);
                }
            }
        }
        return sheep_cnt > wolf_cnt ? make_pair(sheep_cnt, 0) : make_pair(0, wolf_cnt);
    };
    int tot_sheep = 0, tot_wolf = 0;
    for(int i=0;i<R;++i) {
        for(int j=0;j<C;++j) {
            // check start each cell
            if(madang[i][j] != '#' && !visit[i][j]){
                auto ret = bfs(i, j);
                tot_sheep += ret.fi;
                tot_wolf += ret.se;
            }
        }
    }
    cout << tot_sheep << ' ' << tot_wolf;
    return 0;
}