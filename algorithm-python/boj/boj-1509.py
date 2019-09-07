# dp
# 펠린드롬 분할
s = input()
n = len(s)
ispal = [[0]*n for _ in range(n)]
for i in range(n):
    ispal[i][i] = 1
for i in range(n-1):
    if s[i] == s[i+1]:
        ispal[i][i+1] = 1
for k in range(3,n+1):
    for i in range(n-k+1):
        j = i + k - 1
        if s[i] == s[j] and ispal[i+1][j-1]:
            ispal[i][j] = 1

dp = [-1]*n
dp[0] = 1
for i in range(n):
    for j in range(i+1):
        if ispal[j][i]:
            if dp[i] == -1 or dp[i] > dp[j-1] + 1:
                dp[i] = dp[j-1] + 1 if j > 0 else 1
print(dp[n-1])
