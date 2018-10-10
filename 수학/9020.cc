#include<cstdio>
#include<vector>
using namespace std;

//골드바흐의 추측
//소수

vector<bool> eratones(int n){
    vector<bool> arr(n+1,true);
    arr[1] = false;
    for(int i=2; i*i<n; i++){
        if(arr[i]){
            for(int j = i*i; j < n; j+=i){
                arr[j] = false;
            }
        }
    }
    return arr;
}
void goldbah(int n, vector<bool> &erat){
    vector<int> ret(2);
    for(int i=n>>1; i <= n; i++){
        if(erat[i] && erat[n-i]){
            printf("%d %d\n",n-i, i);
            break;
        }
    }
}
int main(){
    int t;;
    vector<bool> erat = eratones(10000);
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        goldbah(k, erat);
    }
    return 0;
}