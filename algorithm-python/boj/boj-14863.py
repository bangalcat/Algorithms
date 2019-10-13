# knapsack 문제
import sys
input = sys.stdin.readline
if __name__ == '__main__':
    n, k = map(int, input().split())
    data = [[int(x) for x in input().split()] for _ in range(n)]
    bike_sum_t = 0
    bike_sum_m = 0
    for dd in data:
        bike_sum_t += dd[2]
        bike_sum_m += dd[3]
    dp = [0] * 1000000
    for i in range(n):
        for t in range(k, 0, -1):
            dp[t] = -1
            if t >= data[i][0]:
                dp[t] = max(dp[t], dp[t - data[i][0]] + data[i][1])
            if t >= data[i][2]:
                dp[t] = max(dp[t], dp[t - data[i][2]] + data[i][3])

    print(dp[k])

