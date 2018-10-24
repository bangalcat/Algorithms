/**
    문제 이름 : 경사로
    삼성 SW 기출문제
    좋았던 아이디어 : 경사로 길이 L을 양수와 음수 두가지 형태로 내리막과 오르막 두가지 상태를 모두 검사할 수 있었다.
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
    //cnt는 현재까지 연속된 같은 높이칸 수
    for(int i=0;i<N;i++){
        cnt = 1;
        for(int j=1;j<N;j++){
            if(map[i][j] == map[i][j-1])
                cnt++;
            //cnt가 0 이상이 될떄까지 같은 칸이 나와 주어야 함
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