/*
    문제이름 : 떨어지는 개미
    개고생하면서 풀었다. 일일이 그림 그려가면서 손으로 시뮬레이션하면서 방법찾음
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, l, k;
int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int>> fallenAnts; // 떨어진 개미들
        deque<pair<int,int>> dq; // id가 +인 개미들
        queue<int> q; // +인 애들 넣어둘 필요가있음 (충돌한애들 최종 시간 구하기 위해)
        cin >> n >> l >> k;
        for(int i=0;i<n;i++){
            int p,a;
            cin >> p >> a;
            if(a<0){ // 왼쪽 향해 갈때
                if(dq.empty()) // 마주치는 개미 없으면
                    fallenAnts.push_back({p+1,a});
                else{ // 마주치는 개미가 존재
                    auto rearAnt = dq.front(); // 가장 뒤쪽 개미가 방향 반전됨
                    fallenAnts.push_back({p+1,rearAnt.second}); //떨어질땐 현재 왼쪽가는 개미 위치만큼 시간걸림
                    dq.pop_front(); //나머지 개미들은 연속된 방향전환 후 + 향하게 됨
                    dq.push_back({p,a}); // 현재 개미도 방향 반전됨
                }
            }else{
                //오른쪽 향해 간다면 일단 저장
                dq.push_back({p,a});
                q.push(p);
            }
        }
        while(!dq.empty()){ //오른쪽 가는 개미들 떨어지는거 계산
            auto ant = dq.front();
            dq.pop_front();
            int m=0;
            if(!q.empty()){
                m = q.front();//L에서 빼줄 값
                q.pop();
            }else
                m = ant.first;
            fallenAnts.push_back({l-m+1,ant.second});
        }
        sort(fallenAnts.begin(),fallenAnts.end());
        cout << fallenAnts[k-1].second<<endl;
    }

    return 0;
}
