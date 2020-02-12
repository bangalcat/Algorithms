# 상근이의 여행
# silver 3
import collections

f = open('algorithm-python/boj/training/test.in', 'r')
input = f.readline

def solve():
    n, m = map(int, input().split())
    ret = 0
    adjlist = collections.defaultdict(int)
    for i in range(m):
        a, b = map(int, input().split())
        adjlist[a].append(b)
        adjlist[b].append(a)

    parent = list(range(n + 1))
    def find(u):
        if parent[u] == u:
            return u
        parent[u] = find(parent[u])
        return parent[u]
    
    def merge(u, v):
        u = find(u)
        v = find(v)
        if u != v:
            parent[u] = v
    
    
    return ret


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        print(solve())