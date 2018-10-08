#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[1001];
    int d[1001];
    for (int i=0; i < n ; i++)
        cin >> arr[i];
    d[0] = 1;
    int max_dp=0;
    for(int i=0; i < n; i++){
        max_dp = 0;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && d[j] > max_dp){
                max_dp = d[j];
            }
        }
        d[i] = max_dp + 1;
    }
    for (int i=0; i<n ; i++)
        if(max_dp < d[i])
            max_dp = d[i];
    cout << max_dp;
    return 0;
}
