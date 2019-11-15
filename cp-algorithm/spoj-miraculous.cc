#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, h, b, e;
    while(~scanf("%d %d %d %d", &n, &h, &b, &e)){
        vector<int> arr(n);
        for(int i=0;i<n;++i) {
            cin >> arr[i];
        }
        deque<pair<int,int>> dq;
        vector<int> ret(n, 0);
        for(int i=b-1; i<e; ++i) {
            if(not dq.empty()) {
                if(dq.front().first + h <= i)
                    dq.pop_front();
                while(not dq.empty() and dq.back().second >= arr[i])
                    dq.pop_back();
            }
            dq.push_back({i, arr[i]});
            ret[dq.front().first] += 1;
        }
        for(int i=b-1; i<e; ++i)
            printf("%d ", ret[i]);  
        printf("\n");
    }
    return 0;
}