#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

vector<Point> mouse, speed;
int n;

double dist(double time) {
    double minX = mouse[0].x + speed[0].x * time;
    double maxX = minX;
    double minY = mouse[0].y + speed[0].y * time;
    double maxY = minY;
    for(int i=0;i<n;++i) {
        minX = min(mouse[i].x + speed[i].x * time, minX);
        maxX = max(mouse[i].x + speed[i].x * time, maxX);
        minY = min(mouse[i].y + speed[i].y * time, minY);
        maxY = max(mouse[i].y + speed[i].y * time, maxY);
    }
    double line = max(maxX - minX, maxY - minY);
    return line;
}

double solve() {
    double lo = 0;   
    double hi = 2000;
    for(int iter = 0; iter < 1000; ++iter) {
        double aab = (lo * 2 + hi) / 3.0;
        double abb = (lo + hi * 2) / 3.0;
        if(dist(aab) > dist(abb))
            lo = aab;
        else
            hi = abb;
    }
    return min(dist(hi), dist(lo));
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) {
        int px, py, vx, vy;
        cin >> px >> py >> vx >> vy;
        mouse.push_back({px,py});
        speed.push_back({vx,vy});
    }
    cout << fixed << setprecision(9) <<solve() << endl;
    return 0;
}