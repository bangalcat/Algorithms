import sys
from array import array
input = sys.stdin.readline

class FenwikTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = array('i', [0]*(self.n+1))
        for i in range(self.n):
            self.add(i+1, arr[i])

    def add(self, idx, r):
        while idx <= self.n:
            self.tree[idx] += r
            idx += (-idx & idx)

    def sum(self, idx):
        ret = 0
        while idx > 0:
            ret += self.tree[idx]
            idx -= (-idx & idx)
        return ret

    def rsum(self, l, r):
        return self.sum(r) - self.sum(l - 1)


if __name__ == '__main__':
    case_n = 0
    N = int(input())
    while N > 0 :
        case_n += 1
        print('Case {}:'.format(case_n))
        arr = [int(input()) for _ in range(N)]
        ft = FenwikTree(arr)
        line = input().strip()
        while line != 'END':
            o, a, b, = line.split()
            a, b = int(a), int(b)
            if o == 'S':
                ft.add(a, b - arr[a-1])
            else:
                print(ft.rsum(a, b))
            line = input().strip()
        print()
        N = int(input())
