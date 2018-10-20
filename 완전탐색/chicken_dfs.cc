/*
    문제 이름 : 치킨 배달
    전역 변수와 재귀 함수를 이용한 조합 탐색
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
vector<pair<int,int>> choosenCks;
//m개 선택했으면 최소값 산출
//변하는 값은 idx와 cnt. 즉 idx를 더해가면서 cnt개 만큼 고르는것
void dfs(int idx, int cnt, int m, const VPII& buyers, const VPII& cks){
    if(cnt == m){
        int mindist=0;
        for(int i=0,len=buyers.size();i<len;i++){
            int temp=10000;
            for(int j=0;j<choosenCks.size();j++)
                temp = min(temp,dist(choosenCks[j],buyers[i]));
            mindist += temp;
        }
        ans = min(ans, mindist);
        return;
    }
    if(idx == cks.size()) return;
    //현재 idx를 선택했을 경우
    choosenCks.push_back(cks[idx]);
    dfs(idx+1,cnt+1, m, buyers, cks);
    //현재 idx를 선택하지 않았을 경우
    choosenCks.pop_back();
    dfs(idx+1,cnt, m, buyers, cks);
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    VPII buyers;
    VPII cks;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int a;
            cin >> a;
            if(a==1) buyers.push_back({i,j});
            else if(a==2) cks.push_back({i,j});
        }

    dfs(0,0,m,buyers,cks);
    cout << ans;
    return 0;
}
