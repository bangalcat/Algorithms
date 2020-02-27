
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int M, n;
    cin >> M >> n;
    // E(1, 0) N(0, 1) W(-1, 0) S(0, -1)
    int xyinc[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    int curd = 0;
    vector<pair<string, int>> orders;
    int cur_pos[2] = {0, 0};
    for(int i=0; i<n; ++i) {
        string a; int d;
        cin >> a >> d;
        orders.push_back({a, d});
    }
    for(auto& p: orders) {
        if(p.first == "MOVE") {
            cur_pos[0] += xyinc[curd][0] * p.second;
            cur_pos[1] += xyinc[curd][1] * p.second;
        } else {
            if(p.second == 0){
                curd = (4 + curd - 1) % 4;
            }else {
                curd = (curd + 1) % 4;
            }
        }
        //range check
        if(cur_pos[0] < 0 || cur_pos[0] > M || cur_pos[1] < 0 || cur_pos[1] > M){
            cout << -1;
            return 0;
        }
    }
    cout << cur_pos[0] << ' ' << cur_pos[1];
    return 0;
}