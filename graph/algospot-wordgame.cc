/*
   알고스팟 : 단어제한 끝말잇기
   오일러 회로 문제
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adjCnt;
vector<int> graph[26][26];
vector<int> indegree;
vector<int> outdegree;

int n;

void makeGraph(const vector<string>& wordList){
    for(int i=0; i< 26; ++i){
        for(int j=0; j <26; ++j){
            graph[i][j].clear();
        }
    }
    adjCnt = vector<vector<int>>(26, vector<int>(26, 0));
    indegree = outdegree = vector<int>(26, 0);
    for(int i=0; i < wordList.size() ; ++i){
        int a = wordList[i].front() - 'a';
        int b = wordList[i].back() - 'a';
        graph[a][b].push_back(i);
        adjCnt[a][b]++;
        outdegree[a]++;
        indegree[b]++;
    }
}
void dfs(int here, vector<int>& ret){
    for(int i=0; i<adjCnt.size(); ++i){
        while(adjCnt[here][i] > 0){
            adjCnt[here][i]--;
            dfs(i, ret);
        }
    }
    ret.push_back(here);
}


vector<int> euler(){
    vector<int> ret;
    //find trail start
    for(int i=0;i<26;++i){
        if(indegree[i] == outdegree[i] - 1){
            dfs(i, ret);
            return ret;
        }
    }
    for(int i=0;i<26;++i) {
        if(outdegree[i]){
            dfs(i, ret);
            return ret;
        }
    }
    return ret;
}


bool checkEuler(){
    int delta_plus =0, delta_minus = 0;
    for(int i=0; i<n; ++i){
        int delta = outdegree[i] - indegree[i];
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) delta_plus++;
        if(delta == -1) delta_minus++;
    }
    return (delta_plus ==1 && delta_minus == 1 ) || (delta_plus == 0 && delta_minus == 0);
}


string solve(const vector<string>& wordList){
    makeGraph(wordList);
    if(!checkEuler()) return "IMPOSSIBLE";
    vector<int> elist = euler();
    if(elist.size() != n+1) return "IMPOSSIBLE";
    
    reverse(elist.begin(), elist.end());
    string ans("");
    for(int i=1;i<elist.size();++i){
        int a = elist[i-1], b = elist[i];
        if(ans.size()) ans+=" ";
        ans += wordList[graph[a][b].back()];
        graph[a][b].pop_back();
    }
    return ans;
}

int main()
{
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        vector<string> wordList(n);
        for(int i=0;i<n;++i){
            string word; cin >> word;
            wordList[i] = word;
        }
        
        cout << solve(wordList) << '\n';
    }

    return 0;
}
