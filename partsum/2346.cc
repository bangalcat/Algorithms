// 풍선 터뜨리기
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n; cin >> n;
    deque<pair<int,int>> jos;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        jos.push_back({i+1,a});
    }
    for(int i=0;i<n;++i){
        auto p = jos.front(); jos.pop_front();
        cout << p.first << ' ';
        for(int i=1;i<p.second;++i)
            jos.push_back(jos.front()),jos.pop_front();
        for(int i=p.second+1;i<0;++i)
            jos.push_front(jos.back()),jos.pop_back();
    }

    return 0;
}