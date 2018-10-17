/*
    문제 이름 : 분해합
    생성자 216 = 216 + 2 + 1 + 6  = 225
*/
#include <iostream>

using namespace std;

int divSum(int n){
    int sum = n;
    while(n){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    int n; cin >> n;
    int ret;
    for(int i=1;i<n;i++){
        if((ret = divSum(i))==n){
            cout << i;
            break;
        }
        if(i==n-1)
            cout << 0;
    }

    return 0;
}
