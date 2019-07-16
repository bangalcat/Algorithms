#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int visit[100001] = {0};
    visit[n] = 1;
    queue<int> que;
    que.push(n);
    while(!que.empty()) {
        int f= que.front();
        que.pop();
        if(f == k) break;
        if(f - 1 >= 0 && visit[f-1] == 0){
            visit[f-1] = visit[f] + 1;
            que.push(f-1);
        }
        if(f + 1 <= 100000 && visit[f+1] == 0){
            visit[f+1]= visit[f]+1;
            que.push(f+1);
        }
        if(f * 2 <= 100000 && visit[f*2] == 0){
            visit[f*2] = visit[f]+1;
            que.push(f*2);
        }
    }
    cout << visit[k] - 1 << endl;
    return 0;
}