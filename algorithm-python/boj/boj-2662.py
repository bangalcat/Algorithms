n, m = map(int, input().split())
profits = [[]]
dp = [[0] * (n+1) for _ in range(m+1)]
for i in range(n):
    profits.append([int(x) for x in input().split()])

for i in range(1, m+1):
    for j in range(1, n+1):
        dp[i][j] = max(dp[i][j-1], profits[j][i])
        for k in range(1, i):
            dp[i][j] = max(dp[i][j], dp[k][j-1] + profits[j][i-k])

print(dp[m][n])
