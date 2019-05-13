
#include <bits/stdc++.h>

using namespace std;

int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};

bool isRange(int r,int c,int n,int m){
    return r>=0 && r<n && c>= 0 && c< m;
}

int main(){
    int T; cin >> T;
    for(int t=1;t<=T;++t){
        map<vector<int>,char> cache;
        int R, C;
        int ans=0;
        cin >> R >> C;
        vector<string> board(R);
        for(int i=0;i<R;++i)
            cin >> board[i];

        auto ptb = [&](int r,int c){
            return r * R + c;
        };

        function<bool(int,int,int)> canPlay = [&](int r, int c, int type){
            if(board[r][c]=='#' || board[r][c]=='*')
                return false;
            for(int d=0;d<4;++d){
                if(d%2!=type) continue;
                int nr = dr[d]+r, nc = dc[d]+c;
                while(isRange(nr, nc, R, C)){
                    if(board[nr][nc] =='#')
                        return false;
                    else if(board[nr][nc]=='*')
                        break;
                    // else board[nr][nc]='*';
                    nr = dr[d]+nr, nc = dc[d]+nc;
                }
            }
            return true;
        };
        auto putPlay = [&](int r,int c, int type, char p){
            board[r][c] = p;
            for(int d=0;d<4;++d){
                if(d%2!=type) continue;
                int nr, nc;
                nr = dr[d]+r, nc = dc[d]+c;
                while(isRange(nr, nc, R, C)){
                    if(board[nr][nc]==p)
                        break;
                    else board[nr][nc]='p';

                    nr = dr[d]+nr, nc = dc[d]+nc;
                }
            }
        };
        function<char(vector<int>)> canWin = [&](vector<int> state){
            char &ret = cache[state];
            if(ret !=0) return ret;
            for(int i=0;i<R;++i){
                for(int j=0;j<C;++j){
                    for(int type=0;type<2;++type){
                        if(canPlay(i, j, type)){
                            putPlay(i, j, type, '*');
                            vector<int> ns = state;
                            ns[ptb(i,j)]=type+1;
                            ret = canWin(ns);
                            putPlay(i, j, type, '.');
                            if(ret==-1) return (char)1;
                        }
                    }
                }
            }
            return ret;
        };
        vector<int> state(R*C);
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                for(int type=0;type<2;++type){
                    if(canPlay(i,j,type)){
                        putPlay(i, j, type, '*');
                        vector<int> ns = state;
                        ns[ptb(i,j)] = type+1;
                        if(canWin(ns)==-1) ans++;
                        putPlay(i, j, type,'.');
                    }
                }
            }
        }
        cout << "Case #";
        cout << t << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}