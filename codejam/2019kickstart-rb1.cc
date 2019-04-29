#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc, ans=0;
    int n, q;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t)
    {
        ans = 0;
        string s;
        vector<int> alphapos[26];
        scanf("%d %d",&n, &q);
        cin >> s;
        for(int i=0;i<n;++i){
            alphapos[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<q;++i){
            int l, r;
            scanf("%d %d", &l, &r);
            int oddcnt=0;
            for(int a=0;a<26;++a){
                auto v = alphapos[a];
                auto cntl = lower_bound(v.begin(),v.end(), l-1);
                auto cntr = upper_bound(v.begin(),v.end(), r-1);
                if((cntr - cntl)% 2) oddcnt++;
            }
            if(oddcnt <= 1) ans++;
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}