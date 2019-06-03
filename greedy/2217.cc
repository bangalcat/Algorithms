#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> rope(n);
    for(int i=0;i<n;++i){
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());
    int ans = 0;
    for(int i=0;i<n;++i){
        ans = max(ans, rope[i] * (n-i));
    }
    cout << ans;
    return 0;
}