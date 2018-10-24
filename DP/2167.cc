/*
    문제 이름 : 2차원 배열의 합
    간단하지만 배열의 부분합을 계산할때 중요하게 쓰이는 아이디어
*/
#include<iostream>
using namespace std;
int arr[301][301];
int sum[301][301];
int main(){
    int n,m,k;
    cin >> n >> m;
    for(int i=1; i <= n ; i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    cin >> k;
    while(k--){
        int i,j,x,y;
        cin >> i >> j >> x >> y;
        int res = sum[x][y] - sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1];
        cout << res << endl;
    }
    return 0;
}