// problem : 녹색 옷 입은 애가 젤다지?

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};

bool isRange(int r,int c, int n)
{
    return r>=0 && r<n && c>= 0 && c<n;
}

int dijkstra(vector<vector<int>>& cave)
{
    int n = cave.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    vector<vector<int>> costs(n,vector<int>(n,-1));
    pq.push({-cave[0][0],{0,0}});
    costs[0][0] = cave[0][0];
    while(!pq.empty())
    {
        auto curr = pq.top();
        int cost = -curr.first;
        int r = curr.second.first;
        int c = curr.second.second;
        pq.pop();
        if(costs[r][c]!=-1 && costs[r][c] < cost) continue;
        for(int d=0;d<4;++d)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(isRange(nr,nc,n) && (costs[nr][nc]==-1 || cave[nr][nc] + cost < costs[nr][nc]))
            {
                costs[nr][nc] = cost + cave[nr][nc];
                pq.push({-costs[nr][nc],{nr,nc}});
            }
        }
    }
    return costs[n-1][n-1];
}

int main()
{
    for(int t=1;; ++t)
    {
        int N; cin >> N;
        if(!N) break;
        vector<vector<int>> cave(N,vector<int>(N,0));
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                cin >> cave[i][j];
        auto ans = dijkstra(cave);
        cout << "Problem " << t << ": " << ans << '\n';
    }
    return 0;
}