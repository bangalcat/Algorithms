/*
    문제 이름 : 주사위 굴리기
    시뮬레이션
*/
#include <iostream>
#include <vector>
using namespace std;

int dr[4] = {0,0,-1,1}, dc[4]={1,-1,0,0};
struct Dice{
    int r,c;
    int top;
    int bottom;
    int east;
    int west;
    int north;
    int south;
    Dice(int r,int c,int t, int b, int e, int w,int n, int s):
    r(r), c(c),
    top(t),bottom(b),east(e),west(w),north(n),south(s) {}
    //회전
    void rotate(int dir){
        if(dir == 0){
            int temp = bottom;
            bottom = east;
            east = top;
            top = west;
            west = temp;
        }else if(dir==1){
            int temp = bottom;
            bottom = west;
            west = top;
            top = east;
            east = temp;
        }else if(dir==2){
            int temp = bottom;
            bottom = north;
            north = top;
            top = south;
            south = temp;
        }else if(dir==3){
            int temp = bottom;
            bottom = south;
            south = top;
            top = north;
            north = temp;
        }
    }
    //이동(회전 후 이동)
    void move(int dir,int n,int m, vector<vector<int>>& board){
        int nr = r+dr[dir], nc = c+dc[dir];
        if(nr <0 || nr >= n || nc< 0 || nc >= m)
            return;
        rotate(dir);
        cout << top << endl;
        if(board[nr][nc] == 0) board[nr][nc] = bottom;
        else {
            bottom = board[nr][nc];
            board[nr][nc] = 0;
        }
        r = nr; c = nc;
    }
};
int main()
{
    int n,m, c,r,k;
    cin >> n >> m >> r >> c >> k;
    vector<vector<int>> board(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    Dice dice(r,c,0,0,0,0,0,0);
    for(int i=0;i<k;i++){
        int order;
        cin >> order;
        dice.move(order-1,n,m,board);
    }

    return 0;
}