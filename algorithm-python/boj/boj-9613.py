import sys
input = sys.stdin.readline
T = int(input())
def gcd(a, b):
    if a < b: return gcd(b, a)
    return gcd(b, a % b) if a % b > 0 else b

for _ in range(T):
    nlist = list(map(int, input().split(' ')[1:]))
    sum = 0
    for i, a in enumerate(nlist):
        for b in nlist[i+1:]:
            sum += gcd(a, b)
    print(sum)

