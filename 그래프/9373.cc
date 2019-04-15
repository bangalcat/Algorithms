/*
    백준 : 복도 뚫기
    MST
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

const double INF = 9987654321;

struct Sensor
{
    int x, y, r;
    Sensor(int x, int y, int r):x(x),y(y),r(r){}
};

int W, N;
vector<Sensor> slist;
vector<vector<double>> interDist;

double calcInter(int s1, int s2)
{
    int xd = slist[s1].x-slist[s2].x;
    int yd = slist[s1].y-slist[s2].y;
    double ret = sqrt(xd*xd+yd*yd) - slist[s1].r - slist[s2].r;
    if(ret <0) return 0;
    return ret;
}

double prim_pq()
{
    if(N==0) return W;
    priority_queue<pair<double, int>> pq; 
    vector<bool> added(N,0);
    vector<double> minDist(N,INF);
    double ret = 0;
    pq.push({0,0});
    minDist[0] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(added[u]) continue;
        added[u] = true;
        ret = max(ret,minDist[u]);
        for(int v=0;v<N;++v)
        {
            double dist; 
            if((slist[u].x-W/2>0)!=(slist[v].x-W/2>0))
                dist = min(interDist[u][v], max((double)(slist[v].x-slist[v].r), (W - (double)slist[v].x)-slist[v].r));
            else dist = max((double)(slist[v].x-slist[v].r), (W - (double)slist[v].x)-slist[v].r);
            if(u!=v && !added[v] && minDist[v] > dist)
            {
                minDist[v] = dist;
                pq.push({-minDist[v], v});
            }
        }
    }
    return ret;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> W >> N;
        interDist = vector<vector<double>>(N,vector<double>(N,0));
        slist.clear();
        for(int i=0;i<N;++i)
        {
            int x, y, r;
            cin >> x >> y >> r;
            slist.push_back({x,y,r});
        }
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                if(i!=j)
                    interDist[i][j] = calcInter(i, j);
        // auto cmp = [](Sensor s1, Sensor s2){
            // return (s1.y == s2.y ? (s1.x == s2.x?s1.r < s2.r:s1.x<s2.x) : s1.y < s2.y);
        // };
        // sort(slist.begin(),slist.end(),cmp);
        printf("%f\n",prim_pq()/2);
    }
    return 0;
}