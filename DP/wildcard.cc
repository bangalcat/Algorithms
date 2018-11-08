/*
    알고스팟 문제 : WILDCARD
    유용했던 것 : int& ret = cache[wIdx][sIdx] 이부분
    ret을 바꾸는 것으로 cache 배열 값을 변경할 수 있다는 점
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cache[101][101];

bool matches(const string& wildcard, const string& text,int wIdx, int sIdx){
    int& ret = cache[wIdx][sIdx];
    if(ret != -1) return ret;
    if(sIdx < text.size() && wIdx < wildcard.size() && (wildcard[wIdx] == '?' || wildcard[wIdx] == text[sIdx])){
        return ret = matches(wildcard,text,wIdx+1,sIdx+1);
    }
    if(wIdx == wildcard.size()) 
        return ret = (sIdx == text.size());
    if(wildcard[wIdx] == '*')
        if(matches(wildcard,text,wIdx+1,sIdx) || (sIdx < text.size() && matches(wildcard,text,wIdx,sIdx+1)))
            return ret = 1;
    return ret = 0;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        string wildcard;
        cin >> wildcard;
        cin >> n;
        string ans[51];
        string t;
        int cnt=0;
        for(int i=0;i<n;i++){
            memset(cache,-1,sizeof(cache));
            cin >> t;
            if(matches(wildcard,t,0,0))
                ans[cnt++] = t;
        }
        sort(ans,ans+cnt);
        for(int i=0;i<cnt;i++)
            cout << ans[i] << endl;
    }
    return 0;
}