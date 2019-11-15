#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double y,x;
};
vector<Point> hull1, hull2;
//위 껍질에 속하는 선분들과 아래 껍질에 속하는 선분들
vector<pair<Point,Point>> upper, lower;

void decompose(const vector<Point>& hull) {
    int n = hull.size();
    for(int i = 0; i<n; ++i) {
        if(hull[i].x < hull[(i+1)%n].x)
            lower.push_back({hull[i], hull[(i+1)%n]});
        else if(hull[i].x > hull[(i+1)%n].x)
            upper.push_back({hull[i], hull[(i+1)%n]});
    }
}
// [a.x, b.x] 구간 안에 x가 포함되나 확인한다.
bool between(const Point& a, const Point& b, double x) {
    return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
// (a, b) 선분과 주어진 위치의 수직선이 교차하는 위치를 반환한다.
double at(const Point& a, const Point& b, double x) {
    double dy = b.y - a.y, dx = b.x - a.x;
    return a.y + dy *(x - a.x) / dx;
}
//두 다각형의 교집합을 수직선으로 잘랐을때 단면의 길이를 반환한다.
double vertical(double x) {
    double minUp = 1e20, maxLow = -1e20;
    // 위 껍질의 선분을 순회하며 최소 y 좌표를 찾는다.
    for(int i = 0; i < upper.size(); ++i) {
        if(between(upper[i].first, upper[i].second, x))
            minUp = min(minUp, at(upper[i].first, upper[i].second, x));
    }
    //아래 껍질의 선분을 순회하며 최대 y좌표를 찾는다.
    for(int i = 0; i < lower.size(); ++i)
        if(between(lower[i].first, lower[i].second, x))
            maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
    return minUp - maxLow;
}

double minX(const vector<Point>& plist){
    double x = plist[0].x;
    for(auto p : plist)
        x = min(x, p.x);
    return x;
}
double maxX(const vector<Point>& plist){
    double x = plist[0].x;
    for(auto p : plist)
        x = max(x, p.x);
    return x;
}

double solve() {
    // 수직선이 두 다각형을 모두 만나는 x좌표의 범위를 구한다.
    double lo = max(minX(hull1), minX(hull2));
    double hi = min(maxX(hull1), maxX(hull2));
    // 두 다각형이 아예 겹치지 않는 경우
    if(hi < lo) return 0;
    //삼분 탐색
    for(int iter = 0; iter < 100; ++iter) {
        double aab = (lo*2 + hi) / 3.0;
        double abb = (lo + hi*2) / 3.0;
        if(vertical(aab) < vertical(abb))
            lo = aab;
        else {
            hi = abb;
        }
    }
    return max(0.0, vertical(hi));
}

int main()
{
    int T; cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        hull1.clear(); hull2.clear();
        upper.clear(); lower.clear();
        for(int i=0;i<n;++i){
            double x,y; cin >> x >> y;
            hull1.push_back({y,x});
        }
        for(int i=0;i<m;++i){
            double x,y; cin >> x >> y;
            hull2.push_back({y,x});
        }
        decompose(hull1);
        decompose(hull2);
        printf("%.8f\n", solve());
    }

    return 0;
}