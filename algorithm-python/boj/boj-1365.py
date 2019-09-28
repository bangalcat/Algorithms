# 백준 꼬인 전깃줄
import bisect
n = int(input())
arr = (int(x) for x in input().strip().split())
C = []
for num in arr:
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)

print(n - len(C))
