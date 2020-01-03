#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<long long> psum(N+1, 0);
    for(int i=0;i<N;++i){
        cin >> arr[i];
        psum[i+1] = psum[i] + arr[i];
    }
    long long ret = 0;
    for(int i=0;i<N;++i){
        ret += (arr[i] * (psum[N] - psum[i+1]));
    }
    cout << ret;
    return 0;

}