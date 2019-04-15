/*
    삼성 SW Academy 문제
    프로세서 연결하기
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <set>
 
using namespace std;
 
int dr[4] ={0,1,0,-1}, dc[4]={1,0,-1,0};
int board[13][13]={0,};
int n;
void recover(int,int,int,int);
//연결 가능한지 한쪽 방향에 대해 검사하고 가능하면 맵채우기
pair<bool,int> checkAndFill(int r, int c,int d){
    bool possible=true;
    int tr= r, tc = c;
    int len=0;
    while(tr+dr[d] >= 0 && tr+dr[d] < n && tc+dc[d] >= 0 && tc+dc[d] < n){
        if(board[tr+dr[d]][tc+dc[d]]) {
            possible=false;
            break;
        }
        tr+=dr[d],tc+=dc[d];
        board[tr][tc] = 2;
        ++len;
    }
    if(!possible){
        recover(r,c,d,len);
    }
    return {possible,len};
}
//맵 복구
void recover(int r,int c,int d,int len){
    int i=0;
    while(i++ < len){
        if(board[r+dr[d]][c+dc[d]]==2)
            board[r+dr[d]][c+dc[d]] = 0;
        r+=dr[d],c+=dc[d];
    }
}
pair<int,int> dfs(int i, int len, int cnt,const vector<pair<int,int>> &cores){
    pair<int,int> ret{0,0};
    if(i==cores.size()){
        return {cnt,len};
    }
    auto core = cores[i];
    //4방향 탐색해서 전선 연결
    for(int d=0;d<4;d++){
        //코어 위치 부터 d방향 맵 끝까지
        auto f = checkAndFill(core.first,core.second,d);
        //다음 탐색
        if(!f.first) continue;
        auto t = dfs(i+1,len+f.second,cnt+f.first, cores);
         
        if(ret.first < t.first) ret = t;
        else if(ret.first==t.first && ret.second > t.second) ret = t;
        //이전 맵 복구 
        if(f.first)
            recover(core.first,core.second,d,f.second);
    }
    //연결 안하고 다음 코어로 넘김
    auto t = dfs(i+1,len,cnt,cores);   
    if(ret.first < t.first) ret = t;
    else if(ret.first==t.first && ret.second > t.second) ret = t;
     
    return ret;
}
int main(){
    int t;
    cin >> t;
    int idx=1;
    while(t--){
        cin >> n;
        vector<pair<int,int>> cores;
        for(int i=0;i<n; i++)
            for(int j=0;j<n;j++){
                cin >> board[i][j];
                //가장자리 코어나 코어로 둘러쌓인 코어들은 미리 걸러서 탐색하지 않도록
                if(board[i][j] && !(i<=0 || i>=n-1 || j<=0 || j>=n-1)){
                    if(board[i-1][j]&&board[i][j-1]&&board[i+1][j]&&board[i][j+1]) continue;
                    cores.push_back({i,j});
                }
            }
        auto ret = dfs(0,0,0,cores);
        cout << "#"<< idx++<< " " << ret.second<< endl;
    }
    return 0;
}