/*
    백준 : 틀렸습니다.
    가로세로 퍼즐 최대한 충돌 없게 연결하기
*/
#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int main()
{
    vector<vector<int>> adj;
    vector<string> board;
    int H, V;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> H >> V;
        adj = vector<vector<int>>(V + H);
        board = vector<string>(2001, string(2001,0));
        vector<vector<int>> hid(2001, vector<int>(2001,-1));

        for (int i = 0; i < H; ++i)
        {
            int x, y;
            string s;
            cin >> x >> y >> s;
            for (int j = 0; j < s.size(); ++j) {
                board[y][x+j] = s[j];
                hid[y][x+j] = i;
            }
        }
        for(int i = 0; i < V; ++i){
            int x, y;
            string s;
            cin >> x >> y >> s;
            for(int j=0;j<s.size();++j){
                //connect edge when conflict(not equal) character
                if(board[y+j][x] != 0 && board[y+j][x] != s[j]){
                    adj[i].push_back(hid[y+j][x]);
                }
            }
        }

        // 이분 매칭
        vector<int> B(H, -1);
        vector<bool> visit;

        function<bool(int)> dfs = [&](int here) {
            if(visit[here]) return false;
            visit[here] = true;
            for (int next : adj[here])
            {
                if (B[next] == -1 || dfs(B[next])) {
                    B[next] = here;
                    return true;
                }
            }
            return false;
        };

        auto bipartite = [&](){
            int size = 0;
            for(int start=0; start < V; ++start){
                visit = vector<bool>(V, false);
                if(dfs(start)) ++size;
            }
            return size;
        };

        cout << V+H - bipartite() << endl;
    }
    return 0;
}
