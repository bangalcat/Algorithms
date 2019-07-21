#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main(){
    int n; cin >> n;
    for(int i=1;i<n;++i){
        for(int j=i; j>1; j/=2)
            arr[j] = arr[j/2];
        arr[1] = i+1;
    }
    arr[n] = 1;
    for(int i=1;i<=n;++i)
        cout << arr[i] << ' ';
    return 0;
}