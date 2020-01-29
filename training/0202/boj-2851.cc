// 슈퍼 마리오

#include <iostream>

using namespace std;

int arr[10];

int main() {
    for(int i=0; i < 10; ++i) {
        cin >> arr[i];
    }
    int ret = 0;
    for(int i=0; i < 10; ++i) {
        if(abs(ret + arr[i] - 100) > abs(ret - 100)){
            break;
        }
        ret += arr[i];
    }

    cout <<ret;
    return 0;
}