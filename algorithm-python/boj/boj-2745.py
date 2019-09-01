# 진법변환
T = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n, b = input().split(' ')
ret = 0
b = int(b)
for i, c in enumerate(n[::-1]):
    v = T.index(c)
    ret += v * (b ** i)

print(ret)
