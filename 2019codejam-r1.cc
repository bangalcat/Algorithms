#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int R, C;

struct Point
{
    int r, c, f, k;
    Point(int r,int c,int f,int k):r(r),c(c),f(f),k(k){}
};

int main()
{
    int tc;
    cin >> tc;
    string s;
    for(int t=1;t<=tc;++t)
    {
        cin >> R >> C;
        vector<vector<int>> space(R,vector<int>(C,0));
        vector<pair<int,int>> ret(R*C);
        int visit[2][21][21]={0};
        queue<Point> que;
        vector<pair<int,int>> start;
        int startcnt=1;
        int stt=0;
        s = "IMPOSSIBLE";
        que.push({0,0,0,1});
        while(!que.empty())
        {
            auto curr = que.front();
            que.pop();
            int f = curr.f;
            int r = curr.r, c = curr.c;
            if(visit[f>0][r][c]) continue;
            visit[f>0][r][c] = curr.k;
            if(curr.k == R*C) {
                stt = curr.f;
                s = "POSSIBLE";
                break;
            }
            for(int i=0;i<R;++i)
            {
                if(!f && i==r) continue;
                for(int j=0;j<C;++j)
                {
                    if(visit[f>0][r][c]) continue;
                    if(r==i || c==j || r+c == i+j || r-c==i-j) 
                        if(!f) continue;
                        else{
                            que.push({i,j,startcnt++,curr.k+1});
                            start.push_back({i,j});
                            continue;
                        }
                    que.push({i,j,f,curr.k+1});
                }
            }
        }
        cout << "Case #" << t << ": " << s << '\n';
        if(s == "POSSIBLE")
        {
            for(int i=0;i<R;++i)
                for(int j=0;j<C;++j)
                {
                    if(visit[stt>0][i][j] < stt)
                        ret[R*C-(stt-visit[stt>0][i][j])] = {i,j};
                    else
                    {
                        ret[visit[stt>0][i][j] - stt] = {i,j};
                    }
                }
            for(int i=0;i<R*C;++i)
                cout << ret[i].first + 1 << ' ' << ret[i].second + 1 << '\n';
        }
    }
    return 0;
}