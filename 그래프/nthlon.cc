#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999999;

int main()
{
    int tc; cin >> tc;
    while(tc--)
    {
        int M; cin >> M;    
        vector<pair<int,int>> timeDiffs;
        vector<vector<pair<int,int>>> adj(401); // <-weight,next>
        for(int i=0;i<M;++i)
        {
            int a, b;
            cin >> a >> b;
            timeDiffs.push_back({a-b,a});
        }
        vector<pair<int,int>> srcZero;
        for(int i=0;i<=400;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(i + timeDiffs[j].first >= 0 && i + timeDiffs[j].first <= 400)
                {
                    if(i==200) srcZero.push_back({i + timeDiffs[j].first, timeDiffs[j].second});
                    else
                        adj[i].push_back({i + timeDiffs[j].first, timeDiffs[j].second});
                }
            }
        }
        vector<int> times(401,INF);
        priority_queue<pair<int,int>> pq;
        pq.push({0, -1});
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int t = -curr.first;
            int here = curr.second;
            if(here == -1)
            {
                for(auto there : srcZero)
                {
                    int cost = there.second;
                    if(times[there.first] > times[here] + cost)
                    {
                        times[there.first] = times[here] + cost;
                        pq.push({-times[there.first], there.first});
                    }
                }
                continue;
            }
            for(auto there : adj[here])
            {
                int cost = there.second;
                if(times[there.first] > times[here] + cost)
                {
                    times[there.first] = times[here] + cost;
                    pq.push({-times[there.first], there.first});
                }
            }
        }
        if(times[200] == INF)
            cout << "IMPOSSIBLE\n";
        else
            cout << times[200] << '\n';
    }

    return 0;
}
