import sys
from collections import defaultdict

input = sys.stdin.readline

if __name__=='__main__':
    T = int(input())
    for t in range(1,T+1):
        ans = 0
        n, m = map(int, input().split(' '))
        adj = defaultdict(list)
        for i in range(m):
            a, b = map(int, input().split(' '))
            adj[a].append(b)
            adj[b].append(a)
        visited = [False] * (n+1)

        def dfs(v):
            cnt = 1
            visited[v] = True
            for nxt in adj[v]:
                if not visited[nxt]:
                    cnt += dfs(nxt)
            return cnt

        compcnt = 0
        for v in range(1, n+1):
            if not visited[v]:
                ans += dfs(v)-1
                compcnt += 1
        ans += (compcnt-1)*2

        print('Case #{0}: {1}'.format(t, ans))
