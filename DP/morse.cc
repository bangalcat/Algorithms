/*
    알고스팟 문제 : 모스부호 사전
    k번째 수랑 비슷?
    왜 getBino 재귀함수로 하면 안되고 반복문으로 구한 이항계수는 될까?
*/
#include <iostream>
#include <cassert>

using namespace std;

int N,M,K;
const int LIM = 1e9+100;
int bino[201][201];
void calcbino(){
    for(int i=0;i<=200;i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j=1;j<i;j++)
            bino[i][j] = min(LIM,bino[i-1][j-1]+bino[i-1][j]);
    }
}
//aCb 값
int getBino(int a, int b){
    if(b==0 || b==a) return 1;
    int& ret = bino[a][b];
    if(ret>0) return ret;
    ret = getBino(a-1,b-1) + getBino(a-1,b);
    if(ret > LIM) return ret = LIM;
}
//n과 m 남았을때, k번째 기호
//n이 장음, m이 단음. 장음이 0, 단음이 1
string kmorse(int n,int m, int k){
    if(n==0) return string(m,'o');
    int pivot = bino[n+m-1][n-1];
    if(pivot > k){
        return '-' + kmorse(n-1,m,k);
    }else
        return 'o' + kmorse(n,m-1,k-pivot);
}
int main()
{
    int c;
    cin >> c;
    calcbino();
    while(c--){
        cin >> N >> M >> K;
        cout << kmorse(N,M,K-1) << endl;
    }

    return 0;
}