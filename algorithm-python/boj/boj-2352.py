import bisect
n = int(input())
arr = map(int, input().strip().split())
C = []
for num in arr:
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)

print(len(C))