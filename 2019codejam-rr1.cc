#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; cin >> T;
    for(int tc=1;tc<=T;++tc){
        int P, Q;
        cin >> P >> Q;
        vector<vector<pair<int,int>>> person(4);
        vector<vector<int>> dir(4);
        for(int i=0;i<P;++i){
            int x, y, di, t; char d;
            cin >> x >> y >> d;
            if(d=='N' && y != Q) di = 0, t = y;
            else if(d=='S' && y != 0) di = 1, t = y;
            else if(d=='E' && x != Q) di = 2, t = x;
            else if(d=='W' && x != 0) di = 3, t = x;
            else continue;
            dir[di].push_back(t);
        }
        for (int d = 0; d < 4; ++d){
            sort(dir[d].begin(),dir[d].end());
            if(!d%2) reverse(dir[d].begin(),dir[d].end());
        }
        vector<vector<int>> takes(4,vector<int>(Q,0));
        for (int d = 0; d < 4; ++d) {
            for (auto p : person[d]) {
                if(d==0){
                    for(int y = p.second+1; y<Q;++y)
                        takes[d][y]++;
                }else if(d==1){
                    for(int y=p.second-1;y>=0;--y)
                        takes[d][y]++;
                }else if(d==2){
                    for(int x=p.first+1;x<Q;++x)
                        takes[d][x]++;
                }else if(d==3){
                    for(int x=p.first-1;x>=0;--x)
                        takes[d][x]++;
                }
            }
        }

        cout << "Case #";
        cout << tc << ": ";
        cout << ans.first << ' ' << ans.second;
        cout << '\n';
    }
    return 0;
}