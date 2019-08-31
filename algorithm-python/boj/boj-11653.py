# 수학
# 소인수분해

check = [True] * (10 ** 7 + 10)
for i in range(2, int(len(check) ** 0.5)):
    if check[i]:
        for j in range(i * i, 10**7 + 10, i):
            check[j] = False

primes = [x for x in range(2, 10 ** 7 + 10) if check[x]]

def factorization(n):
    for p in primes:
        while n:
            if n % p == 0:
                print(p)
                n /= p
            else: break

N = int(input())
factorization(N)
