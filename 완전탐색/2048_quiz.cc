#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> board;
bool visited[20][20];

//상하좌우
int DIRECT[4][2] = {
    {-1,0},{1,0},{0,-1},{0,1}
};

//구조체는 queue에 넣을때 편의를 위해
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
    int solve(){
        int ret=0;
        return -1;
    }
};

int main()
{
    int n; cin >> n;
    Solver solver(n,n);
    
    board.assign(n,vector<int>(n));
    for(int i=0;i < n;i++){
        for(int j=0;j<n;j++)
            cin >> board[i][j];
    }

    return 0;
}