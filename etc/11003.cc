#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    int curr_size = 0;
    deque<pair<int,int>> dq;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        if(!dq.empty() && (i - dq.front().first) >= l){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().second > a) {
            dq.pop_back();
        }
        dq.push_back({i,a});

        cout << dq.front().second << ' ';
    }
    return 0;
}