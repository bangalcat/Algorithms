#include <iostream>

using namespace std;

bool isEnd = false;
int N;
char num[82];

void solve(char a, int idx) {
    if(isEnd) return;
    if(idx-1 == N){
        cout << num << endl;
        isEnd = true;
        return;
    }
    num[idx-1] = a;
    for(int i=1;i <= idx / 2; ++i){
        string nums = string(num,idx);
        if(nums.substr(idx - i, i) == nums.substr(idx - i*2, i)){
            num[idx] = '\0';
            return;
        }
    }
    for(int i=1;i<=3;++i)
        solve(i + '0', idx + 1);
    num[idx-1] = '\0';
}

int main()
{
    cin >> N;
    for(int i=1;i<=3;++i)
        solve(i + '0', 1);
    return 0;
}