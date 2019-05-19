#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<string> board(4);
    for(int i=0;i<4;++i)
        cin >> board[i];
    int ans=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(board[i][j] == '.') continue;
            int c = board[i][j] - 'A';
            int t = (abs(c%4 - j) + abs(c/4 - i));
            ans += t;
        }
    }
    cout << ans;
    return 0;
}