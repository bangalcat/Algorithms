#include <bits/stdc++.h>

// 백준 : 열쇠

using namespace std;

int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};

bool isRange(int r, int c, int h, int w) {
    return r>= 0 && r < h && c >= 0 && c < w;
}

int main(){
    int T; cin >> T;
    while(T--) {
        int h, w; cin >> h >> w;
        bool key[26] = {false};
        vector<string> blueprint(h+2,".");
        for(int i=0;i<w+1;++i){
            blueprint[0].push_back('.');
            blueprint[h+1].push_back('.');
        }
        for(int i=1;i<=h;++i){
            string temp;
            cin >> temp;
            blueprint[i] += temp;
            blueprint[i].push_back('.');
        }
        h += 2;
        w += 2;
        string keys;
        int ans = 0;
        cin >> keys;
        for (auto &k : keys)
            if (k == '0') break;
            else if (key[k - 'a'] = true) ;
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<bool> visited(h * w, false);
        while (!que.empty()) {
            auto here = que.front(); que.pop();
            int r = here.first, c = here.second;
            int cell = blueprint[r][c];
            if(visited[r*w+c]) continue;
            if(cell == '$') {
                ans++;
                blueprint[r][c] = '.';
            } else if('a' <= cell && cell <= 'z'){
                if(!key[cell-'a']) {
                    // cout << r << ' ' << c << ' ' << cell << endl;
                    key[cell-'a'] = true;
                    blueprint[r][c] = '.';
                    while(!que.empty()) que.pop();
                    fill(visited.begin(),visited.end(),false);
                }
            } else if('A' <= cell && cell <= 'Z'){
                if(!key[cell - 'A']){
                    visited[r*w+c] = true;
                    continue;
                }
            }
            visited[r*w+c] = true;
            for(int d=0;d<4;++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if(isRange(nr, nc, h, w) && blueprint[nr][nc] != '*')
                    que.push({nr,nc});
            }
        }
        cout << ans << endl;
    }
    return 0;
}