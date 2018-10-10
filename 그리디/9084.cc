#include<iostream>
#include<string.h>
using namespace std;

// 화폐 문제
// 비싼 동전부터 차례로
int main(){
    int t;
    int n, m;
    int coin[21];
    int d[10001];
    cin >> t;
    while(t--){
        memset(d,0,sizeof(d));
        cin >> n;
        for(int i=0; i< n ; i++)
            cin >> coin[i];
        cin >> m;
        d[0] = 1;
        for(int i=0; i<n; i++){
            for(int j=coin[i]; j <= m ; j++){
                d[j] += d[j-coin[i]];
            }
        }
        cout << d[m] << endl;
    }
    return 0;
}