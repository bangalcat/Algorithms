/*
    여행하는 외판원 문제
    shortesetPath() 는 완전탐색
    shortesetPath2()는 비트마스크를 이용한 동적계획법
 */
#include <iostream>
#include <vector>

using namespace std;
#define MAX 12
#define INF 999999999;
int n;
double dist[MAX][MAX];
double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength){
    if(path.size() == n) return currentLength + dist[path[0]][path.back()];
    double ret = INF;
    for(int next=0;next<n;++next){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[next] = true;
        double cand = shortestPath(path, visited, currentLength+dist[here][next]);
        ret = min(cand, ret);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

double cache[MAX][1<<MAX]; // initialized to -1
double shortestPath2(int here, int visited){
    if(visited==(1<<n)-1) return dist[here][0];
    double& ret = cache[here][visited];
    if(ret >= 0) return ret;
    ret = INF;
    for(int next=0;next<n;++next){
        if(visited & (1<<next)) continue;
        ret = min(ret, dist[here][next]+shortestPath2(next,visited+(1<<next)));
    }
    return ret;
}

int main()
{
    return 0;
}
