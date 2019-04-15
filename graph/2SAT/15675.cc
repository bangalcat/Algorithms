#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> map;
vector<vector<int>> adj;
vector<int> discovered;
vector<int> sccIds;
stack<int> st;
int vCount;
int sccCount;

int scc(int here){
    st.push(here);
    int ret = discovered[here] = vCount++;
    for(auto there : adj[here]){
        if(discovered[there] == -1)
            ret = min(ret, scc(there));
        else if(sccIds[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if(ret == discovered[here]){
        while(true){
            int t = st.top();
            st.pop();
            sccIds[t] = sccCount;
            if(t == here) break;
        }
        sccCount++;
    }
    return ret;
}


int main()
{
    int n, m;
    cin >> n >> m;
    int nm = (n+m)*2;
    map = vector<string>(n);
    adj = vector<vector<int>>(nm);
    for(int i=0;i<n;++i){
        cin >> map[i];
        int ii = i * 2;
        for(int j=0;j<m;++j){
            int jj = (j+n)*2;
            if(map[i][j] == '#'){
                // (AU~B)^(~AUB)
                adj[jj].push_back(ii);
                adj[ii+1].push_back(jj+1);
                adj[jj+1].push_back(ii+1);
                adj[ii].push_back(jj);
            }else if(map[i][j] == '*'){
                // (A^~B)U(~A^B) = (A U B)^(~AU~B)
                adj[ii+1].push_back(jj);
                adj[jj+1].push_back(ii);
                adj[jj].push_back(ii+1);
                adj[ii].push_back(jj+1);
            }
        }
    }
    discovered = sccIds = vector<int>(nm,-1);
    vCount = sccCount = 0;
    for(int i=0;i<nm;++i)
        if(discovered[i] == -1)
            scc(i);
    
    for(int i=0;i<nm;i+=2){
        if(sccIds[i] == sccIds[i+1]){
            cout << 0;
            return 0;
        }
    }
    
    cout << 1;
    
    return 0;
}
