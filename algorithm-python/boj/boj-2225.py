N, K = map(int, input().split(' '))
dp = [[0]*201 for _ in range(201)]

def f(n, k):
    if not k: return 0
    elif k==1: return 1
    if dp[n][k] != 0: return dp[n][k]
    dp[n][k] = sum([f(i, k-1) for i in range(n+1)]) % 1000000000
    return dp[n][k]


print(f(N, K) % 1000000000)
