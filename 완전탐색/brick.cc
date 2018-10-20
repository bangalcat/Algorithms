
// 삼성 SW academy 문제
// 문제 이름 : 벽돌 깨기
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
struct Point{
    int r,c;
    Point(int r,int c):r(r),c(c){}
};
//북 동 남 서
int dr[4] ={-1,0,1,0}, dc[4]={0,1,0,-1};
int map[16][14];
int w,h;
int ret=0;

//범위 체크
bool isRange(int r,int c, int n,int m){
    return (r>=0 && r<n && c>=0 && c<m);
}
//공 한개 시뮬레이션
void simulate(int r, int c){
    int cnt = map[r][c];
    map[r][c] = 0;
    if(cnt<=1) return;
    for(int d=0;d<4;d++){
        for(int i=1;i<cnt;i++)
            if(isRange(r+dr[d]*i,c+dc[d]*i,h,w) && map[r+dr[d]*i][c+dc[d]*i])
                simulate(r+dr[d]*i,c+dc[d]*i);
    }
}
//남은 벽돌 정리
void cleanBoard(){
    for(int i=h-2;i>=0;i--){
        for(int j=0;j<w;j++){
            if(map[i][j] && !map[i+1][j]){
                int k = i+1;
                while(k<h && !map[k][j])k++;
                map[k-1][j] = map[i][j];
                map[i][j] = 0;
            }
        }
    }
}
int getScore(){
    int score=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            //cout << map[i][j] << " " ;
            if(map[i][j]) score++;
        }
        //cout << endl;
    }
    //cout << endl;
    
    return score;
}
int solve(int cnt){
    int prevmap[16][14];
    int score=999;
    if(cnt==0) return getScore();
    memcpy(prevmap,map,sizeof(map));
    //한 줄 시뮬레이션
    for(int c=0;c<w;c++){
        for(int r=0;r<h;r++){
            if(map[r][c]){
                simulate(r,c);
                cleanBoard();
                break;
            }
        }
        //한 줄 선택하고 다음 선택으로
        score = min(score, solve(cnt -1));
        if(score == 0) break;
        //맵복구
        memcpy(map,prevmap,sizeof(map));
    }
    
    return score;
}
int main(){
    int t;
    cin >> t;
    int idx=1;
    while(t--){
        int n,ret;
        cin >> n >> w >> h;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        ret = solve(n);
        cout << "#"<< idx++<< " " << ret<< endl;
    }
    return 0;
}