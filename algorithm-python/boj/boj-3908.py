# 백준: 서로 다른 소수의 합
check = [True] * 1121
check[0] = check[1] = False
# 범위내 소수 다 구하기
for i in range(2, int(1120**0.5)+1):
    if check[i]:
        for j in range(i*i, 1121, i):
            check[j] = False

primes = [x for x in range(1, 1121) if check[x]]

# dp[1121][15]
dp = [[0] * 15 for _ in range(1121)]
dp[0][0] = 1
for p in primes:  # 모든 소수에 대해
    for i in range(1120, p-1, -1):  # 어떤 수 i는
        for j in range(1, 15):  # j개 소수로 이루어짐
            dp[i][j] += dp[i-p][j-1]

T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    print(dp[n][k])

