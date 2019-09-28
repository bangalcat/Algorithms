# 백준 : 전깃줄 - 2
# 정렬 후 LIS
# 추적까지

import bisect
n = int(input())
parr = sorted([[int(x) for x in input().strip().split()] for _ in range(n)])
C = []
Cis = []
for i, num in parr:
    num = int(num)
    if C and C[-1] >= num:
        ind = bisect.bisect_left(C, num)
        C[ind] = num
        Cis.append((ind, num))
    else:
        Cis.append((len(C), num))
        C.append(num)
t = len(C) - 1
ret = []
for pos, num in Cis[::-1]:
    if t == pos:
        ret.append(num)
        t -= 1
    if t == -1: break

print(n - len(C))
for i, pnum in parr:
    if pnum not in ret:
        print(i)

