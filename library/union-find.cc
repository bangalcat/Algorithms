#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> parent;
vector<int> ranks;

// support distances up to representative
void make_set(int v) {
    parent[v] = {v, 0};
    ranks[v] = 0;
}

pair<int, int> find_set(int v) {
    if(v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a).first;
    b = find_set(b).first;
    if( a!= b) {
        if(ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = make_pair(a, 1);
        if(ranks[a] == ranks[b])
            ranks[a]++;
    }
}

int main()
{
    return 0;
}