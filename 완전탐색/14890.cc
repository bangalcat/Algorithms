/*
    문제 이름 : 경사로
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <bitset>

using namespace std;

int map[101][101];

int main() {
    int N, L;
    cin >> N >> L;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    
    int road=0;
    int cnt = 1;
    for(int i=0;i<N;i++){
        cnt = 1;
        //서에서 동으로
        for(int j=1;j<N;j++){
            if(map[i][j] == map[i][j-1])
                cnt++;
            else if(cnt >= 0 && map[i][j] == map[i][j-1]+1){
                if(cnt >= L) cnt = 1;
                else break;
            }else if(cnt >=0 && map[i][j] == map[i][j-1]-1){
                cnt = -L+1;
            }else
                break;
            if(cnt >= 0 && j==N-1) road++;
        }
        cnt = 1;
        //북에서 남으로
        for(int j=1;j<N;j++){
            if(map[j][i] == map[j-1][i])
                cnt++;
            else if(cnt >= 0 && map[j][i] == map[j-1][i] +1)
                if(cnt >=L) cnt = 1;
                else break;
            else if(cnt >= 0 && map[j][i] == map[j-1][i]-1)
                cnt = -L+1;
            else break;
            if(cnt >=0 && j==N-1) road++;
        }
    }
    cout << road;
    
    return 0;
}