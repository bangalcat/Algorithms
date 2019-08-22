
# erat
from collections import defaultdict

primes = []
check = [False] * 1000000
for i in range(2, 1001):
    if not check[i]:
        primes.append(i)
        for j in range(i*i, 1000001, i):
            check[j] = True

# problem
n = int(input())
nlist = map(int, input().split(' '))

factor = [defaultdict(int) for _ in range(n)]
usedPrimeCnts = defaultdict(int)

# n개 수에 대해 각 수의 소인수분해 진행. 소수마다의 사용횟수와 해당 수의 소수 사용횟수 기록
for i, num in enumerate(nlist):
    for p in primes:
        if not num % p:
            factor[i][p] += 1
            usedPrimeCnts[p] += 1




