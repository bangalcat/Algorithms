import sys

# input = sys.stdin.readline

f = open("test.in", "r")
input = f.readline


def solve():
    (k, n) = map(int, input().split(' '))
    weights = [list(map(int, input().split(' '))) for _ in range(4)]
    prod = [[] for _ in range(2)]
    prod[0] = [w0 + w1 for w0 in weights[0] for w1 in weights[1]]
    prod[1] = sorted([w2 + w3 for w2 in weights[2] for w3 in weights[3]])
    prod[1] = sorted(prod[1])
    # print(prod[0], prod[1], sep='\n')
    ret = prod[0][0] + prod[1][0]
    for stand in prod[0]:
        lo = -1
        hi = len(prod[1])
        while lo + 1 < hi:
            mid = int((lo + hi) / 2)
            # print(lo, mid, hi, stand, prod[1][mid])
            if stand + prod[1][mid] < k:
                if abs(stand + prod[1][mid] - k) <= abs(ret - k):
                    ret = stand + prod[1][mid]
                lo = mid
            else:
                if abs(stand + prod[1][mid] - k) < abs(ret - k):
                    ret = stand + prod[1][mid]
                hi = mid
        if ret == k: break
    print(ret)


T = int(input())
for _ in range(T):
    solve()

f.close()
