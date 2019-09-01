from collections import defaultdict
from collections import OrderedDict
# erat

check = [False] * (10**6+1)
for i in range(2, 1001):
    if not check[i]:
        for j in range(i*i, 10**6, i):
            check[j] = True

check[1] = check[0] = True
primes = [x for x, f in enumerate(check) if not f]

# problem
n = int(input())
nlist = map(int, input().split(' '))

factor = [defaultdict(int) for _ in range(n)]
usedPrimeCnts = defaultdict(int)
ans, ans_cnt = 1, 0

# n개 수에 대해 각 수의 소인수분해 진행. 소수마다의 사용횟수와 해당 수의 소수 사용횟수 기록
for i, num in enumerate(nlist):
    for p in primes:
        while num % p == 0:
            factor[i][p] += 1
            usedPrimeCnts[p] += 1
            num /= p
for p in primes:
    usedPrimeCnts[p] = usedPrimeCnts[p] // n
    ans = ans * (p ** usedPrimeCnts[p])

for i in range(n):
    for p, ct in usedPrimeCnts.items():
        if ct and factor[i][p] <= ct:
            ans_cnt += ct - factor[i][p]
print(ans, ans_cnt)

