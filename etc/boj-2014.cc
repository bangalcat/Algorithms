#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int k, n;
    cin >> k >> n;
    priority_queue<long long> pq;
    vector<int> arr;

    for(int i=0;i<k;++i){
        int a; cin >> a;
        arr.push_back(a);
        pq.push(-a);
    }
    for(int i=0;i<n-1;++i){
        long long head = -pq.top();
        pq.pop();
        for(int j=0;j<k;++j){
            long long val = head * arr[j];
            pq.push(-val);
            if(head % arr[j] == 0)
               break;
        }
    }
    cout << -pq.top();
    return 0;
}