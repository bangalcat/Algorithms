/*
    문제 이름 : 사다리 조작
    생각이 어려웠던 문제
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map[31][11];

class Solver{
private:
    int n,m,h;
    //현재 map이 조작이 잘 되어있는지 확인
    bool checkComplete(){
        int row=1, col=1;
        //모든 line 검사
        for(int i=1;i<=n;i++){
            row = 1;
            col = i;
            while(row<=h){
                if(map[row][col])
                    col++;
                else if(map[row][col-1])
                    col--;
                row++;
            }
            if(col!=i) return false;
        }
        return true;
    }
public:
    Solver(int n,int m,int h):n(n),m(m),h(h){}
    // 핵심은 r, c로 dfs를 돌리는게 아니라 사다리의 숫자로 돌리는것
    // 조합 경우의 수가 270개 중 1개 또는 2개 또는 3개를 고르도록
    // 단, depth 혹은 현재 row 값을 인자로 주어서 현재 row보다 위쪽은 더이상 살펴보지 않도록
    // 시간복잡도는 ..? 계산 어렵네 10개 line에 30층 깊이
    // 결국 270개 중에 1개 2개 3개를 최대한 중복되지 않게 고르는게 핵심
    int solve(){
        for(int ladder=0;ladder<4;ladder++){
            if(dfs(1,ladder, 0))
                return ladder;
        }
        return -1;
    }
    bool dfs(int height, int remainLadder, int useLadder){
        if(remainLadder == useLadder){
            return checkComplete();
        }
        for(int i=height;i<=h;i++){
            for(int j=1;j<n;j++){
                if(!map[i][j] && !map[i][j-1] && !map[i][j+1]){
                    map[i][j] = 1;
                    if(dfs(i,remainLadder, useLadder + 1))
                        return true;
                    map[i][j] = 0;
                }
            }
        }
        return false;
    }
};


int main()
{
    int n,m,h;
    cin >> n >> m >> h;
    memset(map,0,sizeof(map));
    for(int i=0;i<m;i++){
        int h, b;
        cin >> h >> b;
        map[h][b] = 1;
    }
    Solver solver(n,m,h);
    cout << solver.solve();
    
    return 0;
}