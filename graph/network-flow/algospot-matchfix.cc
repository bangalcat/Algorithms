/*
    알고스팟 : 승부 조작
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 98765431;
const int MAX_V = 102;
vector<vector<int>> capacity, flow;

int N, M;

//source is 0, sink is M+N+1
int networkflow(int source, int sink)
{
    int totFlow = 0;
    while (true)
    {
        //BFS
        vector<int> parent(M+N+2, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;
        while (!q.empty() && parent[sink] == -1)
        {
            int here = q.front();
            q.pop();
            for (int there = 0; there < M+N+2; ++there)
            {
                if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
                {
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if (parent[sink] == -1)
            break;
        int amt = 1;
        for (int p = sink; p != source; p = parent[p])
        {
            flow[parent[p]][p] += amt;
            flow[p][parent[p]] -= amt;
        }
        totFlow += amt;
    }
    return totFlow;
}

//source -> matches -> player -> sink
vector<int> wins;
vector<pair<int, int>> match;
int maxWin = 0;

bool canWinWith(int totWins)
{
    if (maxWin >= totWins)
        return false;
    // player -> sink
    for (int i = 0; i < N; ++i)
    {
        capacity[1 + M + i][M+N+1] = (i==0?totWins:totWins-1) - wins[i];
    }
    return networkflow(0, M+N+1)==M;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> N >> M;
        capacity = flow = vector<vector<int>>(M + N + 2, vector<int>(M + N + 2, 0));
        wins = vector<int>(N);
        match = vector<pair<int, int>>(M);
        int cnt=0;
        for (int i = 0; i < N; ++i)
        {
            cin >> wins[i];
        }
        maxWin = *max_element(wins.begin()+1, wins.end());
        for (int j = 0; j < M; ++j)
        {
            int a, b;
            cin >> a >> b;
            match.push_back({a, b});
            if(a==0 || b==0) cnt++;
        }
        //capacity
        for (int i = 0; i < M; ++i)
        {
            //source -> match
            capacity[0][i + 1] = 1;
            //match -> player
            capacity[i + 1][M + match[i].first + 1] = 1;
            capacity[i + 1][M + match[i].second + 1] = 1;
        }
        for (int i = wins[0]; i <= cnt+wins[0]; ++i)
        {
            if (canWinWith(i)){
                cout << i << '\n';
                break;
            } 
            if(i==cnt+wins[0]) cout << -1 << '\n';
        }
    }
    return 0;
}