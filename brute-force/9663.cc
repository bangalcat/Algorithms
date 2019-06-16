/**
 * boj : N-Queen
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int board[16][16]={0};
bool usedR[16]={0};
bool usedC[16]={0};

int ans=0;

void putQ(int n, int curr,int sr){
    if(curr == n){
        ans++;
        return;
    }
    for(int i=sr;i<n;++i){
        for(int j=0;j<n;++j){
            if(usedC[j] == 0){
                bool flag = false;
                for(int r=0;r<sr;++r){
                    if(!flag) for(int c=0;c<n;++c)
                        if(!flag && board[r][c]==1 && (i-j == r-c || i+j == r+c))
                            flag = true;
                }
                if(flag) continue;
                board[i][j] = 1;
                usedR[i] = usedC[j] = 1;
                putQ(n, curr+1, i+1);
                usedR[i] = usedC[j] = 0;
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n; cin >> n;
    putQ(n,0, 0);
    cout << ans;
    return 0;
}