/*
    백준 : 소수 쌍
    이분 매칭
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<int> A, B, org;
vector<int> odd;
vector<int> even;
map<int, vector<int>> adj;
vector<bool> visited;
int n, first;
vector<bool> eratones;
set<int> ans;

void make_eratones(){
    eratones = vector<bool>(2001,true);
    eratones[1] = false;
    for (int i = 2; i * i < 2001; ++i) {
        if (eratones[i])
            for (int j = i * i; j < 2001; j += i) {
                eratones[j] = false;
            }
    }
}


bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b : even){ 
        if(a == first && ans.find(b)!=ans.end()) continue;
        if(b == first && ans.find(a)!=ans.end()) continue;
        if(eratones[a + b] && (B[b] == -1 || !visited[B[b]] && dfs(B[b]))){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int bipartite(){
    A = vector<int>(1001,-1);
    B = vector<int>(1001,-1);
    int size = 0;
    for (auto start : odd)
    {
        visited = vector<bool>(1001, false);
        size += dfs(start);
    }
    return size;
}
set<int> solve(){
    while(bipartite() == odd.size()){
        ans.insert(first%2==0?B[first]:A[first]);
    }
    return ans;
}

int main()
{
    make_eratones();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if(i==0) first = a;
        if (a % 2)
            odd.push_back(a);
        else
            even.push_back(a);
    }
    if (odd.size() != even.size()) {
        cout << -1 << endl;
    }
    else {
        auto ret = solve();
        if(ret.empty()) cout << -1;
        else for(auto a : ret) cout << a << ' ';
    }

    return 0;
}