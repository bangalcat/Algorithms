#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int findLongcat(unsigned int n){
    int pos=-1, i=0;
    while(n){
        if(!(n&1)) pos = i;
        n >>= 1;
        i++;
    }
    return pos+1;
}

int main()
{
    int n; int next=1;
    scanf("%d", &n);
    int cnt = 0;
    vector<int> ret;
    while (true)
    {
        next = findLongcat(n);
        if (next == 0) break;
        ret.push_back(next);
        n = (n ^ ((1 << next)-1));
        cnt++;
        if(findLongcat(n)==0) break;
        n++;
        cnt ++;
    }
    cout << cnt << '\n';
    if (cnt != 0)
        for (int i = 0; i < ret.size(); ++i)
        {
            cout << ret[i] << ' ';
        }
    return 0;
}