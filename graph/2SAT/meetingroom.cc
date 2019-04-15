#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;

vector<int> sccId; // component num
vector<int> discovered;
stack<int> st; // vertex stack
int sccCnt, vertexCnt;
//return minimal discovered num in subtree which root is here
int scc(int here){
    int ret = discovered[here] = vertexCnt++;
    st.push(here);
    for(int i=0;i<adj[here].size();++i){
        int there = adj[here][i];
        //(here, there) is tree edge
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        //if there is cross edge which need to watch
        else if(sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }
    // is here root of scc component?
    if(ret == discovered[here]){
        while(true){
            int t = st.top();
            st.pop();
            sccId[t] = sccCnt;
            if(t == here) break;
        }
        ++sccCnt;
    }
    return ret;
}
vector<int> tarjanSCC(){
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCnt = vertexCnt = 0;
    for(int i=0; i<adj.size(); ++i)
        if(discovered[i] == -1)
            scc(i);
    return sccId;
}
bool disjoint(const pair<int, int>& a, const pair<int, int>& b){
    return a.second <= b.first || b.second <= a.first;
}

void makeGraph(const vector<pair<int,int>>& meetings){
    int vars = meetings.size();
    adj.clear(); adj.resize(vars * 2);
    for(int i=0; i<vars; i+=2){
        int j = i+1;
        adj[i*2+1].push_back(j*2);
        adj[j*2+1].push_back(i*2);
    }
    for(int i=0;i<vars;++i){
        for(int j=0;j<i;++j){
            //if meet i and j is not disjoint
            if(!disjoint(meetings[i], meetings[j])){
                adj[i*2].push_back(j*2+1);
                adj[j*2].push_back(i*2+1);
            }
        }
    }
}
// adj is implication graph
vector<int> solve2SAT(){
    int n = adj.size() / 2; // number of var
    //tie vertext SCC
    vector<int> label = tarjanSCC();
    //if impossible to solve this 2-SAT problem
    for(int i=0; i<2*n; i+=2)
        if(label[i] == label[i+1])
            return vector<int>();
    vector<int> value(2*n, -1);
    //in tarjan algo, scc num is arrange as reversion of topological sort
    //so sort in decreasing by scc num is state of topol sort
    vector<pair<int,int>> order;
    for(int i=0;i<2*n;++i)
        order.push_back({-label[i], i});
    sort(order.begin(), order.end());
    //arrange
    for(int i=0; i<2*n; ++i){
        int vertex = order[i].second;
        int variable = vertex /2, isTrue = vertex % 2 == 0;
        if(value[variable] != -1) continue;
        //if not A is first, A is true
        //else A is false
        value[variable] = !isTrue;
    }
    return value;
}

int main()
{
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<pair<int,int>> arr;
        for(int i=0; i<n; ++i){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            arr.push_back({a,b});
            arr.push_back({c,d});
        }
        makeGraph(arr);
        auto ret = solve2SAT();
        if(ret.size()==0){
            cout << "IMPOSSIBLE" << '\n';
        }else{
            cout << "POSSIBLE\n";
            for(int i=0;i<ret.size()/2;i+=2){
                if(ret[i])
                    cout << arr[i].first << ' ' << arr[i].second << '\n';
                else
                    cout << arr[i+1].first << ' ' << arr[i+1].second << '\n';
            }
        }
        
    }

    return 0;
}
