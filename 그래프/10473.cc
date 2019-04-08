//인간 대포

#include <iostream>
#include <vector>
using namespace std;

const double INF = 1e9;

double distance(int x, int y, int tx, int ty)
{
    return (x-tx)*(x-tx) + (y-ty)*(y-ty);
}

int main()
{
    int n;
    double sx, sy, tx, ty;
    cin >> sx >> sy;
    cin >> tx >> ty;
    cin >> n;
    vector<pair<double,double>> cannons;
    for(int i=0;i<n;++i)
    {
        double x,y;
        cin >> x >> y;
        cannons.push_back({x,y});
    }
    vector<vector<double>> times(n+2,vector<double>(n+2,INF));
    times[0][0] = 0;
    times[n+1][n+1] = distance(sx,sy,tx,ty)/5;

    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                
            }

    return 0;
}