#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T--) {
        int arr[5];
        int sum = 0;
        for(int i=0;i<5;++i){
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr, arr+ 5);
        if(arr[3] - arr[1] >= 4)
            cout << "KIN";
        else
            cout << sum - arr[0] - arr[4];
        cout << '\n';
    }

    return 0;
}