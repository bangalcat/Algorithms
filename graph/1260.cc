#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//인접 행렬
int adj[1001][1001]={0};
bool isVisited[1001]={0};
bool isVisited2[1001]={0};
int main(){
    queue<int> qe;
    stack<int> st;
    int n, m, v;
    cin >> n >> m >> v;
    for(int i=0; i<m ; i++){
        int c,d;
        cin >> c >> d;
        adj[c][d] = adj[d][c] = 1;
    }
    
    //DFS
    st.push(v);
    isVisited[v] = true;
    cout << v << " ";
    while(!st.empty()){
        int h = st.top();
        st.pop();
        
        for(int i=1; i <= n; i++){
            if(adj[h][i] && !isVisited[i]){
                cout << i << " ";
                isVisited[i] = true;
                st.push(h);
                st.push(i);
                break;
            }
        }
    }
    
    cout << '\n';
    //BFS
    qe.push(v);
    isVisited2[v] = true;
    while(!qe.empty()){
        int h = qe.front();
        qe.pop();
        cout << h << " ";
        for(int i=1; i <= n ; i++){
            if(adj[h][i] && !isVisited2[i]){
                qe.push(i);
                isVisited2[i] = true;
            }
        }
    }
    
    return 0;
}
