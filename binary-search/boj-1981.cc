#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool isRange(int r, int c,int n) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int n;
int arr[101][101];
int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
int minv, maxv;
bool visited[100][100];

bool decision(int diff) {
    for(int v=minv;v<=maxv;++v){
        memset(visited, true, sizeof(visited));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(arr[i][j] >= v && arr[i][j] <= v + diff)
                    visited[i][j] = false;
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            auto here = que.front();
            que.pop();
            if(visited[here/n][here%n]) continue;
            if(here == n * n - 1) return true;
            visited[here/n][here%n] = true;
            for(int d=0;d<4;d++){
                int nr = here/n + dr[d], nc = here%n + dc[d]; 
                if(isRange(nr,nc,n) && !visited[nr][nc]){
                    que.push(nr * n + nc);
                }
            }
        }
    }
    return false;
}

int main(){
    cin>> n;
    minv = 200;
    maxv = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            cin>> arr[i][j];
            minv = min(arr[i][j], minv);
            maxv = max(arr[i][j], maxv);
        }
    int l = 0, r = maxv - minv;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        // cout << l << ' ' << r << ' ' << mid << endl;
        if(decision(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return 0;
}