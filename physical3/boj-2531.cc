#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> sushi(N);
    for(int i=0;i<N;++i)
        cin >> sushi[i];
    int start = 0;
    int end = k-1;
    vector<int> bucket(d+1,0);
    int type_cnt = 0;
    int ans = 0;
    //count initial state sushi type
    for(int i=start; i<=end; ++i){
        if(!bucket[sushi[i]]) type_cnt++;
        bucket[sushi[i]]++;
    }
    if(++bucket[c]==1) type_cnt++;
    ans = type_cnt;
    // move end, start gradually
    while(start < N) { // until come back
        // result of moving start
        if(--bucket[sushi[start]] == 0){
            type_cnt--;
        }
        start++;    // move start
        end = (end + 1) % N;    //move end
        // result of moving end
        if(++bucket[sushi[end]] == 1){
            type_cnt++;
        }
        ans = max(ans, type_cnt);
    }
    cout << ans << endl;

    return 0;
}