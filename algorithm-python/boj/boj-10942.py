# dp
# 펠린드롬?
import sys
input = sys.stdin.readline
n = int(input())
nlist = [int(x) for x in input().strip().split(' ')]
m = int(input())
dp = [[False] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = True
for i in range(n-1):
    if nlist[i] == nlist[i+1]:
        dp[i][i+1] = True
for rng in range(3, n+1):
    for s in range(n-rng+1):
        e = s + rng - 1
        if nlist[s] == nlist[e] and dp[s+1][e-1]:
            dp[s][e] = True

for _ in range(m):
    s, e = map(int, input().strip().split(' '))
    print(1 if dp[s-1][e-1] else 0)
