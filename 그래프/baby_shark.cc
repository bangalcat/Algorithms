/*
    문제 이름 : 아기 상어
    삼성 SW 역테 '18 하반기 오후 2번문제
    우선순위가 존재하는 BFS
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int map[21][21];
//int printmap[21][21];
int visited[21][21][401];
int n;
//북 서 동 남
int dr[4] = {-1,0,0,1}, dc[4] = {0,-1,1,0};
struct Point{
    int r,c,k;
    Point(int r,int c,int k):r(r),c(c),k(k){}
};

bool operator<(const Point& q, const Point& p){
    if(q.k == p.k) 
        return q.r==p.r?q.c>p.c:q.r>p.r;
    else return q.k > p.k;
}
int size=2;
int eat=0;
int totEat=0;
int way=0;
int fishCnt[10];
bool isRange(int r,int c,int n,int m){
    return (r>=0 && r<n && c>=0 && c<m);
}
int m=0;
int main()
{
    cin >> n;
    priority_queue<Point> q;
    int r,c;
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                q.push({i,j,0});
                map[i][j] = 0;
            }else if(map[i][j]>0) fishCnt[map[i][j]]++;
        }
    }
    for(int i=2;i<9;i++)
        fishCnt[i] += fishCnt[i-1];
    
    while(!q.empty()){
        int nr,nc; 
        auto p = q.top();
        q.pop();
        if(visited[p.r][p.c][totEat]) continue;
        if(map[p.r][p.c] == 0 || map[p.r][p.c] == size){
            visited[p.r][p.c][totEat] = 1;
        }else if(map[p.r][p.c] < size){
            eat++;
            map[p.r][p.c] = 0;
            //printmap[p.r][p.c] = p.k; // 출력용 맵
            way = p.k;
            totEat++;
            if(eat==size){
                size++;eat=0;
            }
            if(totEat>=fishCnt[size>6?6:size-1]){
                break;
            }
            visited[p.r][p.c][totEat] = 1;
            while(!q.empty())q.pop();
        }else{
            continue;
        }
        for(int d=0;d<4;d++){
            nr = p.r+dr[d], nc = p.c+dc[d];
            if(isRange(nr,nc,n,n) && !visited[nr][nc][totEat]){
                q.push({nr,nc,p.k+1});
            }
       }
    }
    if(totEat==0)
        cout << 0;
    else
        cout << way;
    return 0;
}
