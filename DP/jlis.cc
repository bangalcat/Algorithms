/*
    알고스팟 문제 : 합친 LIS
    numeric_limits::min() 으로 해당 자료형 최솟값 구할수 있음
*/

#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

int lArr[101], rArr[101];
int N,M;
int cache[101][101];
//마이너스 64bit 최솟값
const long long NEGINF = numeric_limits<long long>::min();

int jlis(int lstart, int rstart){
    int& ret = cache[lstart+1][rstart+1];
    if(ret != -1) return ret;
    ret = 2;
    long long last = NEGINF;
    if(lstart!=-1 || rstart!=-1){
        if(lstart==-1) last = rArr[rstart];
        else if(rstart==-1) last = lArr[lstart];
        else
            last = max(lArr[lstart], rArr[rstart]);
    }
    for(int left=lstart+1; left < N; ++left){
        if(last < lArr[left])
            ret = max(ret, 1+jlis(left,rstart));
    }
    for(int right=rstart+1; right < M; ++right){
        if(last < rArr[right])
            ret = max(ret, 1+jlis(lstart,right));
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        memset(cache,-1,sizeof(cache));
        cin >> N >> M;
        for(int i=0;i<N;i++)
            cin >> lArr[i];
        for(int j=0;j<M;++j)
            cin >> rArr[j];
        cout << jlis(-1,-1) - 2 << endl;
    }
    
    return 0;
}
