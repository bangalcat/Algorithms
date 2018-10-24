/*
    삼성 SW Academy 문제
    핀볼 게임
    웜홀 처리에 주의 
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <set>
 
using namespace std;
struct Point{
    int r,c;
    Point(int r,int c):r(r),c(c){}
};
//북 동 남 서
int dr[4] ={-1,0,1,0}, dc[4]={0,1,0,-1};
int map[102][102];
int n;
int ret=0;
int simulate(int sr, int sc,int d, vector<pair<Point,Point>>& wHole){
    int score=0;
    int nr=sr, nc=sc;
    while(true){
        //한 칸 전진
        nr = nr + dr[d], nc = nc+dc[d]; 
        //장애물 검사
        //1. 벽 - 방향 전환, 점수 +1
        if(map[nr][nc] >=1 && map[nr][nc] <6){
            if(map[nr][nc] == 1){
                d = (d+2)%4 - (d==3) + (d==2);
            }else if(map[nr][nc]==2){
                d = (d+2)%4 - (d==0) + (d==3);
            }else if(map[nr][nc]==3)
                d = (d+2)%4 - (d==1) + (d==0);
            else if(map[nr][nc]==4)
                d = (d+2)%4 - (d==1)*3 + (d==2)*3;
            else d = (d+2)%4;
            score++;
        }
        //2. 웜홀 - 위치 이동
        else if(map[nr][nc] >= 6){
            //반대편 웜홀 찾기
            auto wp = wHole[map[nr][nc]-6];
            //cout << nr << " " << nc << endl;
            if(wp.first.r == nr && wp.first.c == nc){
                nr = wp.second.r;
                nc = wp.second.c;
            }else{
                nr = wp.first.r;
                nc = wp.first.c;
            }
            //cout << "new "<< nr << " " << nc << endl;
        }
        //3. 블랙홀or시작위치 - 게임 종료 
        else if(map[nr][nc] == -1 || (nr==sr && nc==sc)){
            ret = max(ret,score);
            break;
        }
    }
}
int main(){
    int t;
    cin >> t;
    int idx=1;
    for(int i=0;i<102;i++)
        map[i][0] = map[0][i] = 5;
    while(t--){
        vector<pair<Point,Point>> wHole(5,{{0,0},{0,0}});
        ret = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            map[n+1][i] = map[i][n+1] = 5;
            for(int j=1;j<=n;j++){
                cin >> map[i][j];
                if(map[i][j] > 5) 
                    //웜홀쌍을 서로 찾을수 있도록 연결해서 저장
                    if(wHole[map[i][j]-6].first.r == 0) wHole[map[i][j]-6].first = {i,j};
                    else wHole[map[i][j]-6].second = {i,j};
            }
        }
        //모든 빈칸에서 시작해보는 시뮬레이션
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(map[i][j] == 0)
                    for(int d=0;d<4;d++)
                        simulate(i,j,d,wHole);
        }
         
        cout << "#"<< idx++<< " " << ret<< endl;
    }
    return 0;
}