#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getSuffixArray(const string& s){
    int n = s.size();
    vector<int> suffixArray(n);
    vector<int> group (n+1);
    for(int i=0;i<n;i++) suffixArray[i]=i,group[i]=s[i];
    group[n] = -1;
    for(int t=1; t< n; t<<=1){
        auto cmp = [&group,t](int i,int j){
            if(group[i]==group[j]) return group[i+t]<group[j+t];
            else return group[i] < group[j];
        };
        sort(suffixArray.begin(), suffixArray.end(), cmp);
        vector<int> newGroup(n+1);
        newGroup[suffixArray[0]] = 0;
        newGroup[n] = -1;
        for(int i=1;i<n; i++){
            if(cmp(suffixArray[i-1],suffixArray[i]))
                newGroup[suffixArray[i]] = newGroup[suffixArray[i-1]]+1;
            else
                newGroup[suffixArray[i]] = newGroup[suffixArray[i-1]];
        }
        group = newGroup;
    }
    return suffixArray;
}

int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;++t)
    {
        int ans = 0;
        int n; cin >> n;
        vector<string> strs(n);
        for(int i=0;i<n;++i){
            cin >> strs[i];
            reverse(strs[i].begin(),strs[i].end());
        }
        sort(strs.begin(),strs.end());
        vector<int> used(n,0);
        for(int i=0;i<n-1;++i)
        {
            int sames=0;
            for(int j=0;j<strs[i].size();++j)
            {
                if(j >= strs[i+1].size() || strs[i][j] != strs[i+1][j])
                    break;
                sames++;
            }
            
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}