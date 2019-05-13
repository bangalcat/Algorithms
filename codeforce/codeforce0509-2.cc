#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> count(11);
    vector<int> arr(n+1);
    int maxCnt=0;
    int maxCntNum=0;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        arr[i] = a;
        count[a]++;
    }
    auto findMin = [&]() {
        for (int i = 1; i <= 10; ++i) {
            if (count[i] == 0)
                continue;
            if (maxCnt < count[i])
                maxCntNum = i;
            maxCnt = max(maxCnt, count[i]);
        }
    };
    auto check = [&](){
        for(int i=1;i<=10; ++i){
            if(count[i]!=0){
                for(int j=1;j<=10;++j){
                    if(count[j] != 0 && count[j] != count[i])
                        break;
                    if(j==10) return true;
                }
                int t=0;
                t = count[i]-1;
                
                for(int j=1;j<=10;++j){
                    if(t==0) t = count[j];
                    if(i==j)continue;
                    if(count[j] != 0 && count[j] != t)
                        break;
                    if(j==10) return true;
                }
            }
        }
        return false;
    };
    for(int i=n-1;i>=0;--i){
        if(check()) {
            cout << i+1;
            return 0;
        }else{
            count[arr[i]]--;
            if(count[arr[i]] == 0){

            }
        }
    }
    cout << 1;
    return 0;
}