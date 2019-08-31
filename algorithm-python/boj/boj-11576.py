# 수학
# Base Conversion

a, b = map(int, input().split(' '))
m = int(input())
mlist = [int(x) for x in input().split(' ')]

ten = 0
for i, num in enumerate(mlist[::-1]):
    ten += num * (a ** i)

ans = []
while ten:
    v, r = divmod(ten, b)
    ans.append(r)
    ten = v

print(*ans[::-1], sep=' ')
