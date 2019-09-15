n = int(input())
nlist = [int(x) for x in input().split()]
# 두 높이의 차가 0이 되어야함
# 더하거나 빼거나
dp = [[-1] * 500001 for _ in range(n+1)]
dp[0][0] = 0
ret = -1
for i, h in enumerate(nlist):
    for j in range(500001):
        if dp[i][j] != -1:
            dp[i+1][j] = max(dp[i][j], dp[i+1][j])
            if j + h <= 500000:
                dp[i+1][j+h] = max(dp[i+1][j+h], dp[i][j] + h)
            if 0 <= h - j <= 500000:
                dp[i+1][h-j] = max(dp[i+1][h-j], dp[i][j] + h - j)
            if j - h >= 0:
                dp[i+1][j-h] = max(dp[i+1][j-h], dp[i][j])

ret = dp[n][0]
print(ret if ret else -1)
