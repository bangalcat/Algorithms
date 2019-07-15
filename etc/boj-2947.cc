#include <iostream>

using namespace std;

void print(int arr[5]){
    for(int i=0;i<5;++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void sort(int arr[5]) {
    for(int k=4;k>=0;--k)
        for(int i=0;i<k;++i){
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                print(arr);
            }
        }
}

int main()
{
    int arr[5];
    for(int i=0;i<5;++i)
        cin >> arr[i];
    sort(arr);

    return 0;
}