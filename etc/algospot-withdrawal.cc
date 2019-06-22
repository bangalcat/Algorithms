#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int c[1000], r[1000];

bool decision(double average) {
    vector<double> v;
    for(int i=0;i<n;++i)
        v.push_back(average * c[i] - r[i]);
    sort(v.begin(), v.end());
    double sum = 0;
    for(int i=n-k;i<n;++i){
        sum += v[i];
    }
    return sum >= 0;
}
double optimize(){
    double lo = -1e-9, hi = 1;
    for(int iter = 0; iter < 100; iter++){
        double mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else   
            lo = mid;
    }
    return hi;
}

int main()
{
    int T; cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i=0;i<n;++i)
            cin >> r[i] >> c[i];
        printf("%.10f\n", optimize());
    }
    return 0;
}