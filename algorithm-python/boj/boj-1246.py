
f = open("test.in", "r")
input = f.readline

n, m = map(int, input().rstrip().split(' '))
parr = [int(input().rstrip()) for i in range(m)]

parr = sorted(parr,reverse=True)
ans_price, ans_tot = 0, 0
for i, val in enumerate(parr[:min(n, m)]):
    sump = (i+1) * val
    ans_tot, ans_price = (sump, val) if sump > ans_tot else (ans_tot, ans_price)

print(ans_price, ans_tot)
