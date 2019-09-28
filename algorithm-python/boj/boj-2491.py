# 백준 : 수열
# 부분증가수열이 아닌, 연속해서 증가하거나 감소하는 수열을 찾는것
n = int(input())
arr = [int(x) for x in input().strip().split()]
ret = 1
prev = -1
rprev = -1
l = 0
rl = 0
for num in arr:
    if num >= prev:
        l += 1
    else:
        ret = max(ret, l)
        l = 1
    if num <= rprev:
        rl += 1
    else:
        ret = max(ret, rl)
        rl = 1
    rprev = prev = num
ret = max(ret, l, rl)

print(ret)

