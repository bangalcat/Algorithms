# 북서풍 - (DQUERY 유사)
# FIXME: 왜 런타임 에러인지??? 
from array import array
from collections import OrderedDict
import sys
input = sys.stdin.readline


class Fenwik(object):
    def __init__(self, n: int):
        self.tree = [0] * (n + 2)
        self.n = n + 1

    def add(self, idx, delta):
        idx += 1
        while idx < self.n:
            self.tree[idx] += delta
            idx += (idx & -idx)
        return

    def sum(self, idx):
        ret: int = 0
        idx += 1
        while idx > 0:
            ret += self.tree[idx]
            idx -= (idx & -idx)
        return ret


if __name__ == "__main__":
    T: int = int(input())
    for _ in range(T):
        n: int = int(input())
        ret = 0
        nlist = []
        mappery = OrderedDict()
        yset = OrderedDict()
        for i in range(n):
            x, y = map(int, input().rstrip().split())
            yset[y] = 1
            nlist.append((x, -y))
        idx: int = 0
        for y in sorted(yset.keys(), reverse=True):
            mappery[y] = idx
            idx += 1
        ft: Fenwik = Fenwik(idx)
        nlist = sorted(nlist)
        for x, y in nlist:
            ret += ft.sum(mappery[-y])
            ft.add(mappery[-y], 1)
        print(ret)
