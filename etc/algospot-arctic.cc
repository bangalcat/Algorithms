#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n;
double dist[100][100];

double getDistance(double x, double y, double tx, double ty) {
    return sqrt((x - tx) * (x - tx) + (y - ty) * (y - ty));
}

bool decision(double d) {
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    int seen = 0;
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        ++seen;
        for(int there = 0; there < n; ++there) {
            if(!visited[there] && dist[here][there] <= d){
                visited[there] = true;
                q.push(there);
            }
        }
    }
    return seen == n;
}

double optimize() {
    double lo = 0, hi = 1416.00;
    for(int it = 0; it < 100; ++it) {
        double mid = (lo + hi) / 2;
        if(decision(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int root[100];
int find(int u) {
    if(root[u] == u) return u;
    return root[u] = find(root[u]);
}

double kruskal(){
    vector<pair<double, pair<int, int>>> edges;
    for(int i=0;i<n;++i){
        root[i] = i;
        for(int j=i+1;j<n;++j){
            edges.push_back({dist[i][j], {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    double ret = 0;
    for(auto& e : edges){
        int u = e.second.first, v = e.second.second;
        double d = e.first;
        if(find(u) == find(v)) continue;
        root[find(v)] = find(u);
        ret = max(ret, d);
    }
    return ret;
}

double floyd() {
    double maxd = 0;
    for(int t = 0; t < n; ++t) {
        for(int i=0; i < n; ++i) {
            for(int j = 0; j < n; ++j){
            }
        }
    }
}

int main()
{
    int T; cin >> T;
    while(T--) {
        cin >> n;
        vector<double> px(n);
        vector<double> py(n);
        for(int i=0;i<n;++i){
            cin >> px[i] >> py[i];
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n; ++j)
            {
                if(i==j) dist[i][j] = 0;
                else
                    dist[i][j] = getDistance(px[i],py[i], px[j],py[j]);
            }
        printf("%.2f\n", kruskal());
    }
    return 0;
}