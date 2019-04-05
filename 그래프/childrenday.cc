#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int append(int here, int edge, int mod){
    int there = here * 10 + edge;
    if(there >= mod ) return mod + there % mod;
    return there % mod;
}

string solve(string digits, int n, int m){
    sort(digits.begin(), digits.end());
    vector<int> parent(2*n, -1), choice(2*n, -1);
    queue<int> q;
    parent[0] = 0;
    q.push(0);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i=0; i < digits.size(); ++i){
            int there = append(here, digits[i] - '0', n);
            if(parent[there] == -1){
                parent[there] = here;
                choice[there] = digits[i] - '0';
                q.push(there);
            }
        }
    }
    if(parent[n + m] == -1) return "IMPOSSIBLE";
    string ret;
    int here = n + m;
    while(parent[here] != here){
        ret += char('0' + choice[here]);
        here = parent[here];
    }
    reverse(ret.begin(), ret.end()) ;
    return ret;
}

int main()
{
    int tc; cin >> tc;
    while(tc--){
        string d;
        int n, m;

        cin >> d >> n >> m;
        cout << solve(d, n, m) << '\n';
    }

    return 0;
}
