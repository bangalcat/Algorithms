# 백준 : 열차정렬
import bisect

n = int(input())
arr = (-int(input()) for _ in range(n))
C = []
for num in arr:
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)

print(len(C))
