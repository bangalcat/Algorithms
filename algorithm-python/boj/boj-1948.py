import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
m = int(input())
adjGraph = defaultdict(list)
rAdjGraph = defaultdict(list)
indegree = [0] * (n + 1)
rIndegree = [0] * (n + 1)

for _ in range(m):
    s, d, w = map(int, input().split(' '))
    adjGraph[s].append((d, w))
    rAdjGraph[d].append((s, w))
    indegree[d] += 1
    rIndegree[s] += 1
start, end = map(int, input().split(' '))

dist = [0] * (n+1)
que = [start]
while len(que) != 0:
    here = que.pop()
    for there, wg in adjGraph[here]:
        dist[there] = max(dist[there], dist[here] + wg)
        indegree[there] -= 1
        if indegree[there] == 0:
            que.append(there)


def backtracking():
    ans = 0
    check = [False] * (n + 1)
    que = [end]
    check[end] = True
    while len(que) != 0:
        here = que.pop()
        for there, wg in rAdjGraph[here]:
            if check[here] and dist[here] - dist[there] == wg:
                check[there] = True
                ans += 1
            rIndegree[there] -= 1
            if rIndegree[there] == 0:
                que.append(there)
    return ans

print(dist[end], backtracking(),sep='\n')
