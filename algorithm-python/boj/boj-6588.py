# 수학
# 골드바흐의 추측
import sys, bisect
input = sys.stdin.readline

check = [True] * (10 ** 6 + 10)
for i in range(2, 1001):
    if check[i]:
        for j in range(i * i, 10**6 + 10, i):
            check[j] = False

primes = [x for x in range(3, 10 ** 6 + 10) if check[x]]

for n in sys.stdin:
    n = int(n)
    if n == 0: break
    a, b = 0, 0
    for i, p in enumerate(primes):
        np = n - p
        if p > np: break
        bi = bisect.bisect_left(primes, np)
        if bi < len(primes) and p + primes[bi] == n:
            a, b = p, np
            break
    # else:
    #     print('Goldbach\'s conjecture is wrong')
    sys.stdout.write('{} = {} + {}\n'.format(n, a, b))

