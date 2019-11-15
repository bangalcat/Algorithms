# 백준 : MT
# DP or SCC. SCC로 풀어보자
from collections import defaultdict

def inputs():
    n, k = map(int,input().split())
    arr = [int(x) for x in input().split()]
    return n, k, arr

def solve(n, k, arr):
    adjlist = defaultdict(list)
    for i, xi in enumerate(arr, 1):
        adjlist[i].append(xi)
    cmax = [0] * (n + 1)
    def get_cmax(x):
        cnt = 0
        for i in adjlist[x]:
            cnt += get_cmax(i)
        cmax[x] = cnt
        return cnt
    return

def solve_dp(n, k, arr):
    for i, xi in enumerate(arr, 1):
        pass
    return


if __name__ == '__main__':
    solve(*inputs())
