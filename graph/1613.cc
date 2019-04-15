#include <iostream>
#include <vector>

using namespace std;
//floyd?
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<vector<int>> graph(N, vector<int>(N,0));
    for(int i=0;i<K;++i)
    {
        int a, b; cin >> a>> b;
        graph[a-1][b-1] = 1;
    }
    for(int i=0;i<N;++i)
        graph[i][i] = 1;
    //floyd
    for(int k=0;k<N;++k)
        for(int i=0;i<N;++i)
            if(graph[i][k])
            for(int j=0;j<N;++j)
                graph[i][j] = graph[i][j] | (graph[i][k] & graph[k][j]);
    int S;
    cin >> S;
    for(int i=0;i<S;++i)
    {
        int a, b;
        cin >> a >> b;
        if(graph[a-1][b-1])
            cout << -1 << '\n';
        else if(graph[b-1][a-1])
            cout << 1 << '\n';
        else
        {
            cout << 0 << '\n';
        }
        
    }
    return 0;
}