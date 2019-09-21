# LIS 최장 증가하는 부분 수열 문제
#%%
arr = [1, 2, 7, 5, 10, 4, 6, 6]
n = len(arr)

#%%
# n^2 solution
dp = [0] * n
for i in range(n):
    if dp[i] == 0: dp[i] = 1
    for j in range(i):
        if arr[i] > arr[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

#%%
# nlogk solution
# 배열 C
import bisect
C = []
for i in range(n):
    if C and C[-1] > arr[i]:
        C[bisect.bisect_left(C, arr[i])] = arr[i]
    else:
        C.append(arr[i])

print(C)


