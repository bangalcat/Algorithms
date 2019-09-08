T, W = map(int, input().split())
arr = [0]
dp = [[0] * (W+1) for _ in range(T+1)]
for _ in range(T):
    arr.append(int(input()))

ret = 1
for i in range(1, T+1):
    if arr[i] == 1:
        dp[i][0] = dp[i-1][0] + 1
    else:
        dp[i][0] = dp[i-1][0]
    ret = max(ret, dp[i][0])
    for j in range(1, min(i+1, W+1)):  # j는 움직인 횟수
        if arr[i] == 1 and j % 2 == 0:  # 짝수번 움직임 -> 1번 나무
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
        elif arr[i] == 2 and j % 2 == 1:  # 홀수번 움직임 -> 2번 나무
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])
        ret = max(ret, dp[i][j])
print(ret)

