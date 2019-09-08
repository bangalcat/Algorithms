from collections import defaultdict
DIV = 1000000007
N, L, R = map(int, input().split())
dp = defaultdict(int)
dp[1, 1, 1] = 1
dp[2, 2, 1] = dp[2, 1, 2] = 1
"""
3가지 경우의 수
2~n 건물에 높이 1의 건물 추가
1. 왼쪽끝에 추가 -> l+1, r
2. 오른쪽끝에 추가 -> l, r+1
3. 가운데부분에 추가 -> l, r 유지
"""
# dp[N, 2, 1] = dp[N, 1, 2] = 1
for i in range(3, N+1):
    dp[i, i, 1] = dp[i, 1, i] = 1
    for j in range(1, min(L + 1, i+1)):
        for k in range(1, min(R + 1, i+1)):
            if not dp[i, j, k]:
                dp[i, j, k] = dp[i-1, j, k] * (i - 2) + dp[i-1, j, k-1] + dp[i-1, j-1, k]
                dp[i, j, k] %= DIV

print(dp[N, L, R])
