# 0-1 knapsack
n, m = map(int, input().split())
nlist = [int(x) for x in input().split()]
clist = [int(x) for x in input().split()]
INF = 1e9
dp = [0] * 10001

for j in range(n):
    for ci in range(10000, 0, -1):
        if ci >= clist[j]:
            dp[ci] = max(dp[ci], dp[ci-clist[j]] + nlist[j])

for i, v in enumerate(dp):
    if v >= m:
        print(i)
        break
