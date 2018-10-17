/*
    문제 이름 : 감시
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

vector<tuple<int, int, char>> cctvs; // r, c, type
int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
class Solver{
private:
    int n,m;
    vector<vector<char>> map;
    vector<int> dirct; //각 cctv의 direction들 모든 경우의 수 볼수 있도록 담는 임시배열
    //현재 direction 배열 상태로 각 cctv의 감시 영역 채우고 난 후, 사각지대 반환
    int getBlindSpot(vector<int>& dirct){
        vector<vector<char>> tempMap = map;
        int ret=0;
        for(int i=0;i<dirct.size();i++){
            int r,c; char t;
            tie(r,c,t) = cctvs[i];
            for(int d=0;d<4;d++) {
                if(t=='1'&& dirct[i]!=d) continue;
                if(t=='2'&& dirct[i]%2!=d%2) continue;
                if(t=='3'&& (dirct[i]!=d && (dirct[i]+1)%4!=d)) continue;
                if(t=='4'&& dirct[i]==d) continue;
                fill(tempMap, d, r, c);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout << tempMap[i][j] << " ";
                if(tempMap[i][j]=='0') {
                    ret++;
                }
            }
            //cout << '\n';
        }
        return ret;
    }
    //재귀적으로 한 방향으로 막히기 전까지 맵 채우는 함수
    void fill(vector<vector<char>>& map, int d, int r, int c){
        if(r<0 || r>=n || c<0 || c>=m) return;
        if(map[r][c]=='6') return;
        if(map[r][c]=='0')  map[r][c] = '#';
        fill(map,d,r+dr[d],c+dc[d]);
    }
public:
    Solver(int n,int m,vector<vector<char>>& map):n(n),m(m), map(map){
    }
    int solve(){
        int ret=65;
        for(int d=0;d<4;d++)
            ret = min(ret,dfs(0,d,dirct));
        return ret;
    }
    //각 cctv마다 방향 정한 경우의 수
    int dfs(int idx, int d,vector<int>& dirct){
        if(idx == cctvs.size()){
            return getBlindSpot(dirct);
        }
        int ret=65; // 맵이 8x8임
        for(int d=0;d<4;d++){
            dirct.push_back(d);
            ret = min(ret,dfs(idx+1,d,dirct));
            dirct.pop_back();
            char t = get<2>(cctvs[idx]);
            if(t=='2' && d>1) break;
            else if(t=='5') break;
        }
        return ret;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> map(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j]>='1' && map[i][j]<='5')
                cctvs.emplace_back(i,j,map[i][j]);
        }
    Solver solver(n,m,map);
    cout << solver.solve();
    
    return 0;
}