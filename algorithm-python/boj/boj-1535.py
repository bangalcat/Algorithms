n = int(input())
cost = [int(x) for x in input().split()]
joy = [int(x) for x in input().split()]
dp = {}

def f(i, m):
    if i >= n: return 0
    if (i, m) in dp:
        return dp[i, m]
    ans = max(f(i+1, m - cost[i]) + joy[i] if m - cost[i] > 0 else 0, f(i+1, m))
    dp[i, m] = ans
    return ans

print(f(0, 100))

