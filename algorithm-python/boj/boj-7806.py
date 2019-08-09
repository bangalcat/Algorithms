import sys

f = open("test.in","r")
input = f.readline()

primes = []
isprime = [False]*100001

for i in range(2, 40001):
    if not isprime[i]:
        primes.append(i)
        for j in range(i*i, 40001, i):
            isprime[i] = True

# for line in sys.stdin:
for line in f:
    n, k = map(int, line.split(' '))
    i = 2
    ret = 1
    while i**2 <= k:
        powK = 0
        while k % i == 0:
            k //= i
            powK += 1
        if powK:
            powN = 0
            j = i
            while j <= n:
                powN += n // j
                j *= i
            for j in range(0, min(powN, powK)):
                ret *= i
        if k < i: break
        i += 1
    if 1 < k <= n:
        ret *= k
    print(ret)
