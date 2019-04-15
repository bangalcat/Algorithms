/*
    문제 이름 : 드래곤 커브
    브루트 포스 문제
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Point{
    int x; 
    int y;
    bool operator<(const Point& b)const {
        return x < b.x || (x==b.x && y<b.y);
    }
};
// 우 상 좌 하 
int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};

class Solver{
private:
    int lastX, lastY;
public:
    Solver(int x, int y) : lastX(x), lastY(y){}

    // 핵심은 set에다가 점들을 저장해서 전체 도형을 회전시키는것
    // 회전시킬때마다 맨 처음의 시작점이 마지막 점이 되므로 시작점과 마지막점을 계속 유지하면 값 찾기는 쉽다
    void draw(int x, int y, int d, int g, set<Point> &points){
        if(g==0){
            return;
        }
        //재귀적으로 호출해서 0세대부터 거꾸로 계산해서 올라옴
        draw(x, y, d, g-1, points);
        set<Point> newSet;
        //cout << x << " " << y << " " << lastX << " " << lastY << endl;
        for(auto it = points.begin();it!=points.end();++it){
            int nx = lastX - it->y + lastY;
            int ny = lastY + it->x - lastX;
            if(nx >= 0 && nx <= 100 && ny >= 0 && ny <=100)
            newSet.insert({nx,ny});
        }
        int temp = lastX;
        lastX = lastX - y + lastY;
        lastY = lastY + x - temp;
        
        //기존 set에 새로 추가된 점들 union
        points.insert(newSet.begin(),newSet.end());
    }
};
int main()
{
    int n;
    cin >> n;
    int map[101][101] = {0,};
    while(n--){
        int x,y,d,g;
        set<Point> points;
        cin >> x >> y >> d >> g;
        points.insert({x,y});
        points.insert({x+dx[d],y+dy[d]});
        Solver solver(x+dx[d],y+dy[d]);
        solver.draw(x,y,d,g,points);
        for(auto it=points.begin(); it!=points.end();++it)
            map[it->y][it->x] = 1;
    }
    int sqrCnt=0;
    //보는 점에서 오른쪽 아래 사각형 존재 판단
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            //cout << map[i][j] << " ";
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1])
                sqrCnt++;
        }
        //cout << endl;
    }
    cout << sqrCnt;
    
    return 0;
}
