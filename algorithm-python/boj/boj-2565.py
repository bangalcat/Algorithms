# 백준 : 전깃줄
# 정렬 후 LIS

import bisect
n = int(input())
parr = sorted([[int(x) for x in input().strip().split()] for _ in range(n)])
C = []
for _, num in parr:
    num = int(num)
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)
print(n - len(C))

