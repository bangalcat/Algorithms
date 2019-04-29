#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int tc, ans=0;
    int n, s;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t)
    {
        scanf("%d %d",&n, &s);
        ans = 0;
        vector<int> arr(n);
        vector<int> cnts(100001,0);
        vector<int> scnt(n,0);
        for(int i=0;i<n;++i){
            scanf("%d",&arr[i]);
        }
        int l=0, currCnt=0;
        //put right, abandon left
        for (int r = 0; r < n; ++r)
        {
            cnts[arr[r]]++;
            if (cnts[arr[r]] <= s)
                currCnt++;
            else if (cnts[arr[r]] == s + 1)
                currCnt = currCnt - s;
            int prop = l, tempCnt=0, maxT=0;
            map<int,int> temp;
            for (int i = l; i < r; ++i)
            {
                temp[arr[i]]++;
                if(cnts[arr[i]] <= s)
                    tempCnt--;
                else if(cnts[arr[i]] - temp[arr[i]] == s){
                    tempCnt = tempCnt + s;
                    if(tempCnt >= maxT){
                        maxT = tempCnt;
                        prop = i+1;
                    }
                }else{
                    tempCnt--;
                }
            }
            while (prop > l)
            {
                cnts[arr[l]]--;
                l++;
            }
            currCnt = currCnt + maxT;
            l = prop;
            ans = max(ans, currCnt);
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}