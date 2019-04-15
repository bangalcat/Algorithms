/*
    문제 이름 : 벽 부수고 이동하기 2
    메모리 초과, 시간 초과 문제 엄청 생김
    이유 : visited를 true로 바꾸는 시점에 따라 queue에 push되는 양이 문제가 된다.
    visited를 queue에 넣어주기 전에 먼저 true로 하고 넘겨줘야만 함
    why? visited를 queue에서 꺼내는 시점에 true로 해버리면 이미 queue에 동일한 좌표에 동일한 k를 가진
    Point들이 들어가게 되므로 이것이 점점 커지면 감당이 안됨.
    BFS의 특성인듯
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
bool isRange(int r, int c, int n,int m){
    return (r>=0 && r<n && c>=0 && c<m);
}
struct Point{
    int r,c,k,way;
    Point(int r,int c, int k,int way):r(r),c(c),k(k),way(way){}
};

char map[1001][1001];
bool visited[1001][1001][11];
queue<Point> que;
int main()
{ 
    int n,m, k;
    scanf("%d%d%d",&n,&m,&k);
    //vector<string> map(n);
    //vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(k,false)));
    for(int i=0;i<n;i++){
        scanf("%s",&map[i]);
    }
    for(int i=0;i<k;i++)visited[0][0][i]=true;
    que.push({0,0,0,1});
    int minWay=999999999;
    while(!que.empty()){
        auto pt = que.front();
        que.pop();
        if(pt.r==n-1 && pt.c==m-1){
            minWay = pt.way;
            break;
        }
        //4방향 전진
        for(int d=0;d<4;d++){
            int nr = pt.r+dr[d];
            int nc = pt.c+dc[d];
            if(isRange(nr,nc,n,m)){
                if(map[nr][nc]=='1' && pt.k < k){
                    if(!visited[nr][nc][pt.k+1]){
                        //중요!! visited를 여기서 변환해줘야함!
                        visited[nr][nc][pt.k+1] = true;
                        que.push({nr,nc,pt.k+1,pt.way+1});
                    }
                }else if(map[nr][nc]=='0' && !visited[nr][nc][pt.k]){
                    visited[nr][nc][pt.k] = true;
                    que.push({nr,nc,pt.k,pt.way+1});
                }
            }
        }
    }
    if(minWay==999999999)
        puts("-1");
    else
        printf("%d",minWay);
    return 0;
}