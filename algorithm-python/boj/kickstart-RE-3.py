import sys
from collections import defaultdict

f = open('test.in', 'r')
input = f.readline
# input = sys.stdin.readline
rng = 10**7

if __name__=='__main__':
    T = int(input())
    interests = [False] * (rng+1)
    # print(primes)
    spf = [0] * (rng+1)
    pr = []

    def euler_sieve(n):
        pn = 0
        for x in range(2, n):
            if not spf[x]:
                pr.append(x)
                spf[x] = x
                pn += 1
            j = 0
            while x * pr[j] < n:
                spf[x*pr[j]] = pr[j]
                if not x % pr[j]:
                    break
                j += 1
        # print(pn)

    euler_sieve(rng + 1)

    def make_interests(n):
        # 모든 소수에 대해
        for i in range(1,n):
            if i < n/2 and i%2:
                interests[i*2] = True
        for p in pr:
            interests[p] = True
            if p <= n / 4:
                interests[p * 4] = True
        # 예외
        interests[0] = True
        interests[1] = True

    make_interests(rng+1)
    for t in range(1,T+1):
        L, R = map(int, input().split(' '))
        ans = interests[L:R+1].count(True)
        print('Case #{0}: {1}'.format(t, ans))
