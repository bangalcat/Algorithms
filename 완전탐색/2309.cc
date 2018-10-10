#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
    백설 공주와 일곱 난쟁이
*/
int main()
{
    int n;
    vector<int> arr(9);
    int sum=0;
    for(int i=0; i< 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    int a,b;
    for(int i=0; i<8;i++){
        for(int j=i+1; j<9; j++){
            if(sum - arr[i] - arr[j] == 100){
                a= i; b = j;
            }
        }
    }
    for(int i=0;i<9;i++){
        if(i != a && i != b){
            cout << arr[i] << '\n';
        }
    }
    
    return 0;    
}
