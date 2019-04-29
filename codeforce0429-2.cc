
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<string> board(n);
    int empty_cnt=0;
    vector<pair<int,int>> spaces;
    for(int i=0;i<n;++i){
        cin >> board[i];
        for(int j=0;j<n;++j){
            char c = board[i][j];
            if(c=='.') {
                empty_cnt++;
                if(i!=0 && i!= n-1 && j != 0 && j != n-1) spaces.emplace_back(i,j);
            }
        }
    }
    if(empty_cnt % 5) cout << "NO";
    else{
        auto check = [&](int r, int c){
            return board[r][c] == '.' && board[r-1][c] == '.' && board[r+1][c]=='.' && board[r][c-1]=='.' && board[r][c+1]=='.';
        };
        #define ffunc(x) board[r][c]=board[r-1][c]=board[r+1][c]=board[r][c-1]=board[r][c+1]=(x)
        bool isAnsFind=false;
        function<void(int, int)> dfs = [&](int cnt, int remain){
            if(isAnsFind) return;
            if(remain==0) {
                isAnsFind = true;
                return;
            }
            if(cnt==spaces.size()) return;
            int r = spaces[cnt].first, c = spaces[cnt].second;
            if(check(r, c)){
                ffunc('#');
                dfs(cnt+1, remain-5);
                ffunc('.');
            }else
                dfs(cnt+1, remain);
        };
        dfs(0,empty_cnt);
        if(isAnsFind) cout << "YES" ;
        else cout << "NO";
    }
    return 0;
}