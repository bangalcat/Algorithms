#include <iostream>
#include <vector>

using namespace std;

bool decision(const vector<double>& location, int cameras, double gap){
    // greedy
    double limit = -1;
    int installed = 0;
    for(int i = 0; i < location.size(); ++i){
        if(limit <= location[i]) {
            ++installed;
            limit = location[i] + gap;
        }
    }
    return installed >= cameras;
}
// binary search
double optimize(const vector<double>& location, int cameras) {
    double lo = 0, hi = 241;
    for(int it = 0; it < 100; ++it) {
        double mid = (lo + hi) / 2.0;
        if(decision(location, cameras, mid))
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}

int main()
{
    int tc; cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<double> location(m);
        for(int i=0; i<m; ++i)
            cin >> location[i];
        printf("%.2f\n" , optimize(location,n));
    }

}