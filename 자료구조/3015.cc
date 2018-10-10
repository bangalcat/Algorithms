#include <iostream>
#include<vector>
#include<stack>

#define FORI(i, n, s) for(int (i)=s;(i)<(n);(i)++)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> h(n);
    stack<pair<int,int>> st; // pair로 안하면 시간초과 난다.
    long long ret = 0;
    int curr;
    FORI(i, n, 0){
        cin >> curr;
        int same = 0;
        // 같은 키 나왔을때의 처리가 중요
        while(!st.empty() && curr >= st.top().first){
            if(curr==st.top().first) same+=st.top().second;
            ret += st.top().second;
            st.pop();
        }
        
        if(!st.empty())
            ret++;
        st.push({curr,same+1});
    }
    cout << ret;
    return 0;
}