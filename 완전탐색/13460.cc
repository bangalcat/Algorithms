/*
    BFS 완전 탐색 문제
    visited 해주면 좀더 빨리 탐색 
    핵심은 한쪽방향으로 계속 움직일때 빨간 공과 파란 공을 번갈아가면서 움직이는것
*/
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define RV_NEXT board[next_r][next_c]
#define BV_NEXT board[b_next_r][b_next_c]

const char SPACE = '.';
const char WALL = '#';
const char GOAL = 'O';
const char RB = 'R';
const char BB = 'B';

vector<vector<char>> board;
int visited[10][10][10][10];
//상하좌우
int DIRECT[4][2] = {
    {-1,0},{1,0},{0,-1},{0,1}
};

struct Point{
    int r;
    int c;
    Point(int r,int c):r(r),c(c){};
};

class Solver{
private:
    int N;
    int M;
    queue<tuple<Point,Point,int>> q;
public:
    Solver(int n, int m):N(n),M(m){}
    int solve(int startR, int startC, int BstartR, int BstartC){
        int ret=0;
        q.emplace(Point(startR,startC), Point(BstartR, BstartC), 0);
        visited[startR][startC][BstartR][BstartC] = 1;
        while(!q.empty()){
            //탐색할 점 꺼내기
            Point nowR = get<0>(q.front()); 
            Point nowB = get<1>(q.front());
            int cnt = get<2>(q.front());
            //tie(nowR,nowB,cnt) = q.front();
            q.pop();
            visited[nowR.r][nowR.c][nowB.r][nowB.c]=1;
            //다음 점 4방향 만들기
            for(int i=0; i<4; i++){
                int dR = DIRECT[i][0];
                int dC = DIRECT[i][1];
                int next_r = nowR.r ;
                int next_c = nowR.c ;
                int b_next_r = nowB.r ;
                int b_next_c = nowB.c ;
                bool r_f = false, b_f = false; // 계속 움직일수 있는지 여부
                
                //벽 나올때까지 한방향으로 계속 이동
                while(!r_f || !b_f){
                    //공끼리 부딪히는 케이스 - 이전 위치로 복귀시킨다
                    //빨간공이 움직였거나, 파란공이 움직였거나
                    //단, GOAL에 빠진거면 복귀시키면 안됨
                    if(BV_NEXT != GOAL && next_r == b_next_r && next_c == b_next_c){
                        if(!r_f){ //빨간공 움직임 복귀
                            next_r-=dR;
                            next_c-=dC;
                        }else{ //파란공 움직임 복귀
                            b_next_r-=dR;
                            b_next_c-=dC;
                        }
                        break;
                    }
                    //벽은 도달하기 전에 멈춰줘야하므로 미리검사
                    //골 도착했어도 파란볼 GOAL 빠졌는지 검사해야함
                    if(board[next_r+dR][next_c+dC] == WALL || RV_NEXT==GOAL)
                        r_f = true;
                    if(board[b_next_r+dR][b_next_c+dC] == WALL || BV_NEXT== GOAL)
                        b_f = true;
                    if(!r_f){
                        next_r+=dR;
                        next_c+=dC;
                    }
                    if(!b_f){
                        b_next_r+=dR;
                        b_next_c+=dC;
                    }
                }
                //파란볼이 빠지면 실패이므로 다음으로 넘어감
                if(BV_NEXT == GOAL){
                    continue;
                }
                if(cnt+1 > 10) continue; // 10번 이상은 더이상 못가게

                //골에 도착했다면 바로 return (BFS이므로) 단, 10 넘으면 안됨
                if(RV_NEXT == GOAL) {
                    return cnt+1;
                }
                if(!visited[next_r][next_c][b_next_r][b_next_c])
                    q.emplace(Point(next_r,next_c),Point(b_next_r,b_next_c),cnt+1);
            }
        }
        return -1;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    Solver solver(n,m);
    int startR,startC,BstartR,BstartC;
    for(;board.size()<n;){
        string line; cin >> line;
        vector<char> v(line.begin(),line.end());
        int c = line.find(RB);
        if(c > 0) {
            startR = board.size();
            startC = c;
            v[startC] = SPACE;
        }
        int bc = line.find(BB);
        if(bc > 0) {
            BstartR = board.size();
            BstartC = bc;
            v[BstartC] = SPACE;
        }
        board.push_back(v);
    }
    //cout << startR << " " << startC;
    cout << solver.solve(startR,startC,BstartR,BstartC);

    return 0;
}
