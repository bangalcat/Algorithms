# 정올 초등부 2004
# 줄세우기

n = int(input())
arr = [(int(x), i) for i, x in enumerate(input().rstrip().split(' '))]
narr = []
for x, i in arr:
    narr.insert(x, i+1)
narr = reversed(narr)
print(*narr)

