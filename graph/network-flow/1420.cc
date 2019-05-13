/*
    백준 : 학교가지마!
    빈 칸을 벽으로 막아서 출발점에서 도착점까지 못가도록 하기
    최소 컷
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

#define MAX_V 20002
#define INF 987654321

using namespace std;

vector<string> board;
vector<vector<int>> adj;

map<pair<int, int>, int> capacity;
map<pair<int, int>, int> flow;
int n, m;

int main()
{
    cin >> n >> m;
    board = vector<string>(n + 1);
    adj = vector<vector<int>>(n * m * 2 + 2);

    int sr, sc, tr, tc;

    int S = -1, T = -1, cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'K')
            {
                S = cnt + 1;
                sr = i;
                sc = j;
            }
            else if (board[i][j] == 'H')
            {
                T = cnt;
                tr = i;
                tc = j;
            }
            cnt += 2;
        }
    }

    if ((n == 1 && m == 1) || abs(sr - tr) + abs(sc - tc) == 1)
    {
        cout << -1;
        return 0;
    }

    //node split
    for (int i = 0; i < n * m; i++)
    {
        capacity[{2 * i, 2 * i + 1}] = 1;
        adj[2 * i].push_back(2 * i + 1);

        capacity[{2 * i + 1, 2 * i}] = 0;
        adj[2 * i + 1].push_back(2 * i);
    }

    // connect edges
    int ss = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (j + 1 < m && board[i][j] != '#' && board[i][j + 1] != '#')
            {
                // right cell
                int ee = ss + 2;
                // ->
                capacity[{ss + 1, ee}] = INF;
                capacity[{ee, ss + 1}] = 0; //reverse edge
                adj[ss + 1].push_back(ee);
                adj[ee].push_back(ss + 1);

                // <-
                capacity[{ee + 1, ss}] = INF;
                capacity[{ss, ee + 1}] = 0; //rev
                adj[ee + 1].push_back(ss);
                adj[ss].push_back(ee + 1);
            }

            if (i + 1 < n && board[i][j] != '#' && board[i + 1][j] != '#')
            {
                // south cell
                int ee = 2 * m + ss;

                // down
                capacity[{ss + 1, ee}] = INF;
                capacity[{ee, ss + 1}] = 0;
                adj[ss + 1].push_back(ee);
                adj[ee].push_back(ss + 1);

                // up
                capacity[{ee + 1, ss}] = INF;
                capacity[{ss, ee + 1}] = 0;
                adj[ee + 1].push_back(ss);
                adj[ss].push_back(ee + 1);
            }

            ss += 2;
        }

    int totalFlow = 0;

    while (true)
    {
        vector<int> prev(MAX_V, -1);
        queue<int> q;
        q.push(S);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int next : adj[cur])
            {
                if (prev[next] != -1)
                    continue;

                if (prev[next] == -1 && capacity[{cur, next}] - flow[{cur, next}] > 0)
                {
                    q.push(next);

                    prev[next] = cur;

                    if (next == T)
                        break;
                }
            }
        }

        if (prev[T] == -1)
            break;

        for (int i = T; i != S; i = prev[i])
        {
            flow[{prev[i], i}] += 1;
            flow[{i, prev[i]}] -= 1;
        }

        totalFlow++;
    }

    cout << totalFlow;
    return 0;
}
