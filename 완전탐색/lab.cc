/*
    문제 이름 : 연구소
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
typedef vector<vector<int>> VVI;
int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};
class Solver{
private:
    int n,m, totZeroCnt;
    queue<pair<int,int>> virusPt;
    //virus들 시뮬레이션 할때는 BFS로 탐색
    int getVirusCnt(VVI map){
        auto tempQ = virusPt;
        int cnt=0;
        while(!tempQ.empty()){
            auto p = tempQ.front();
            tempQ.pop();
            int nr = p.first, nc = p.second;
            if(map[nr][nc]==0)
                cnt++;
            if(totZeroCnt - cnt < ret) return cnt;
            map[nr][nc] = 2;
            for(int d=0;d<4;d++){
                nr = dr[d]+p.first, nc = dc[d]+p.second;
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(map[nr][nc] == 0)
                    tempQ.push({nr,nc});
            }
        }
        return cnt;
    }
public:
    int ret=-9000;
    Solver(int n,int m,int totZeroCnt, queue<pair<int,int>>& vp):
    n(n),m(m),totZeroCnt(totZeroCnt-3),virusPt(vp){}
    int solve(VVI& map){
        pick(0,0,0,map);
        return ret;
    }
    //사다리 조작과 비슷하게 매 재귀마다 전체 맵에서 조합 수를 완
    void pick(int r, int c, int cnt, VVI& map){
        if(cnt == 3){
            ret = max(ret,totZeroCnt - getVirusCnt(map));
            return;
        }
        for(int i=r;i<n;i++){
            for(int j=c;j<m;j++){
                if(map[i][j] == 0){
                    map[i][j] = 1;
                    pick(i,j,cnt+1,map);
                    map[i][j] = 0;
                }
            }
            c = 0;
        }
    }
};
int main()
{
    int n,m, totZeroCnt=0;
    cin >> n >> m;
    queue<pair<int,int>> virusPt;
    VVI map(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]==0)
                totZeroCnt++;
            if(map[i][j]==2)
                virusPt.push({i,j});
        }
    Solver solver(n,m,totZeroCnt,virusPt);
    cout <<solver.solve(map);
    return 0;
}
