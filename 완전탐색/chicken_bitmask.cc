/*
    문제 이름 : 치킨 배달. 삼성 SW '18 상반기
    비트마스크를 이용한 조합 탐색 방법
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<pair<int,int>> VPII;

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second - b.second);
}

int ans = 10000;

int getZeros(int n){
    int cnt = 0;
    while(!(n&1)){
        cnt++;
        n>>=1;
    }
    return cnt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    VPII buyers;
    VPII cks;
    int dists[101][13];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            if(a==1) buyers.push_back({i,j});
            else if(a==2) cks.push_back({i,j});
        }
    for(int i=0;i<buyers.size();i++)
        for(int j=0;j<cks.size();j++)
            dists[i][j] = dist(buyers[i],cks[j]);
    int bit = (1<<m) -1;
    int maxcase = (1<<cks.size())-1;
    while(bit <= maxcase){
        int mindist = 0;
        for(int i=0,len=buyers.size();i<len;i++){
            int temp=1000;
            for(int j=0,bm=1;bm <= bit;j++,bm<<=1)
                if(bm&bit)
                    temp = min(temp,dists[i][j]);
            mindist += temp;
            if(mindist > ans) break;
        }
        cout << mindist << endl;
        ans = min(ans,mindist);
        int temp = bit | ((bit & -bit) - 1);
        bit = (temp + 1) | (((~temp & -~temp) - 1) >> getZeros(bit)+1);
    }

    cout << ans;
    return 0;
}
