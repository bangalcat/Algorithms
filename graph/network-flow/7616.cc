/*
    백준 : 교실로 가는 길
    네트워크 플로우
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <sstream>
#include <algorithm>

#define pb push_back
#define pf push_front

using namespace std;
const int MAX_V = 5001 << 1;
const int INF = 987654321;

int k, n;

struct Edge {
    int target;
    char capacity, flow = 0;
    Edge * rev;
    int remain(){
        return capacity - flow;
    }
    void push(int amt){
        flow += amt;
        rev->flow -= amt;
    }
};

vector<vector<Edge*>> adj;

void addEdge(int u, int v, int capacity){
    Edge* uv = new Edge(), *vu = new Edge();
    uv->target = v;
    uv->capacity = capacity;
    uv->rev = vu;
    vu->target = u;
    vu->capacity = 0;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int networkFlow(int src, int sink, int k){
    int totFlow = 0;
    while(true){
        vector<int> prev(n*2,-1);
        vector<Edge*> path(n*2);
        queue<int> q;
        q.push(src);
        while(!q.empty() && prev[sink]==-1){
            int here = q.front();
            q.pop();
            for(auto edge : adj[here]){
                if(edge->remain() > 0 && prev[edge->target]==-1){
                    prev[edge->target] = here;
                    path[edge->target] = edge;
                    q.push(edge->target);
                }
            }
        }
        if(prev[sink] == -1) break;
        for(int i=sink;i!=src;i=prev[i]){
            path[i]->push(1);
        }
        
        if(++totFlow == k)
            break;
    }
    if(totFlow == k){
        for (int i = 0; i < k; ++i)
        {
            int here = 1;
            while (here != 2)
                for (auto edge : adj[here])
                {
                    if (edge->flow > 0)
                    {
                        if (here % 2)
                            cout << here/2+1 << ' ';
                        edge->flow--;
                        here = edge->target;
                        break;
                    }
                }
            cout << "2\n";
        }
    }
    return totFlow == k;
}
template <typename Out>
void split(const string &s, char delim, Out result)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        *(result++) = item;
    }
}
vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}

int main()
{
    //k : path, n : intersect
    string s;
    int t = 1;
    scanf("%d %d\n", &k, &n);
    while (k && n)
    {
        adj.clear();
        adj.resize(n * 2);
        for (int u = 0; u < n; ++u)
        {
            addEdge(u * 2, u * 2 + 1, 1);
            getline(cin, s);
            auto v = split(s, ' ');
            for (auto sp : v)
            {
                int v = atoi(sp.c_str());
                if(u >= v) continue;
                addEdge(u * 2 + 1, v * 2 - 2, 1);
                addEdge(v * 2 - 1, u * 2, 1);
            }
        }
        cout << "Case " << t++ << ":\n";
        if (!networkFlow(1, 2, k))
            cout << "Impossible\n";
        cout << '\n';

        scanf("%d %d\n", &k, &n);
    }
    return 0;
}