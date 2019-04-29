#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc, ans=0;
    int n;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t)
    {
        scanf("%d",&n);
        vector<int> si(n);
        vector<int> ei(n);
        vector<int> li(n);
        for(int i=0;i<n;++i){
            scanf("%d %d %d",&si[i],&ei[i],&li[i]);
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}