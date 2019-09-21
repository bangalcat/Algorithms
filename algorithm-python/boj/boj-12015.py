import bisect, sys
input = sys.stdin.readline
n = int(input())
arr = (int(x) for x in input().rstrip().split())
C = []
for num in arr:
    if C and C[-1] >= num:
        C[bisect.bisect_left(C, num)] = num
    else:
        C.append(num)

print(len(C))
