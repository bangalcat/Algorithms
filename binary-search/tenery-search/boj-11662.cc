#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double ax, ay, bx, by, cx, cy, dx, dy;
double vxr, vyr;

double dist(double t) {
    return sqrt(pow(ax - cx + (bx - ax) * t * (1 - vxr),2) + pow(ay - cy + (by - ay) * t * (1 - vyr), 2));
}

double solve() {
    double lo = 0;
    double hi = 1;
    for(int iter = 0; iter < 1000; iter++) {
        double aab = (lo * 2 + hi) / 3;
        double abb = (lo + hi * 2) / 3;
        if(dist(aab) > dist(abb))
            lo = aab;
        else
            hi = abb;
    }
    return min(dist(lo), dist(hi));
}

int main()
{
    // (dx - cx) / (bx - ax) = vxc / vxa = vxr
    // (dx - cx) / vxc = T = 1
    // (bx - ax) / vxa = T = 1
    // ((ax + vxa * t) - (cx + vxc * t))^2 + ~
    // ((ax + vxa * t) - (cx + vxa * vxr * t))^2
    // (ax - cx + vxa * t * (1 - vxr)) ^ 2
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    vxr = (dx - cx) / (bx - ax);
    vyr = (dy - cy) / (by - ay);
    cout << fixed << setprecision(10) << solve();
    return 0;
}