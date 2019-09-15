#include <iostream>

using namespace std;
int arr[500001] = {0};

long long mergeSort(int start, int end) {
    if(start == end) return 0;
    int tempArr[end - start + 1] = {0};
    int mid = (start + end) / 2;
    long long ret = mergeSort(start, mid) + mergeSort(mid + 1, end);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid || j <= end) {
        if(i <= mid && (j > end || arr[i] <= arr[j]))
            tempArr[k++] = arr[i++];
        else {
            ret += (mid - i + 1);
            tempArr[k++] = arr[j++];
        }
    }
    for(int i = start; i <= end; ++i)
        arr[i] = tempArr[i - start];
    return ret;
}

int main()
{
    int n;
    cin >> n;   
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cout << mergeSort(0, n-1);
    return 0;
}