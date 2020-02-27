#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        pq.push(a);
    }
    while(m--) {
        long long top = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        pq.push(top + second);
        pq.push(top + second);
    }
    long long ret = 0;
    while(!pq.empty()) {
        ret += pq.top(); pq.pop();
    }
    cout << ret;
    return 0;
}