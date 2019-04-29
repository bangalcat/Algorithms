#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> chests(n);
    vector<int> keys(m);
    for(int i=0;i<n;++i)
        scanf("%d", &chests[i]);
    for(int i=0;i<m;++i)
        scanf("%d", &keys[i]);
    int ch_odd_cnt=0, keys_odd_cnt=0;
    for(int i=0;i<n;++i)
        if(chests[i]%2) ch_odd_cnt++;
    for(int i=0;i<m;++i)
        if(keys[i]%2) keys_odd_cnt++;
    cout << min(ch_odd_cnt,m-keys_odd_cnt)+min(n-ch_odd_cnt,keys_odd_cnt);
    return 0;
}