#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // 구간합 ?
    pair<int,int> coords[1001];
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        coords[i] = {x,y};
    }
    sort(coords, coords + n);
    int psum[1001][1001] = {0};
    int last = -1;
    int idx = 0;
    for(int i=0;i<n;++i){
        if(last != coords[i].first) idx++, last = coords[i].first;
        coords[i].first = idx;
    }
    int xn = idx+1;
    sort(coords, coords+n, [](pair<int,int> a, pair<int,int> b){return a.second == b.second ? a.first < b.first : a.second < b.second;});
    last = -1, idx = 0;
    for(int i=0;i<n;++i){
        if(last != coords[i].second) idx++, last = coords[i].second;
        coords[i].second = idx;
    }
    int yn = idx+1;
    for(int i=0;i<n;++i){
        psum[coords[i].first][coords[i].second]++;
    }
    for(int i=0;i<xn;++i){
        for(int j=0;j<yn;++j){
            psum[i+1][j+1] = psum[i+1][j+1] + psum[i][j+1] + psum[i+1][j] - psum[i][j];
        }
    }
    const int INF = 987654321;
    int ansmin = INF;
    for(int i=1;i<=xn;++i){
        for(int j=1;j<=yn;++j){
            int q1 = psum[i-1][j-1];
            int q2 = psum[xn][j-1] - psum[i-1][j-1];
            int q3 = psum[i-1][yn] - psum[i-1][j-1];
            int q4 = psum[xn][yn] - q1 - q2 - q3;
            int m = max({q1,q2,q3,q4});
            ansmin = min(ansmin, m);
        }
    }
    cout << ansmin;
    
    return 0;
}