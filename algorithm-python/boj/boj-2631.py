# 백준 줄세우기
import bisect
n = int(input())
arr = (int(input()) for x in range(n))
C = []
for num in arr:
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)

print(n - len(C))
