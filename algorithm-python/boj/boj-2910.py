from collections import defaultdict, namedtuple

n, c = map(int, input().split(' '))
arr = map(int, input().split(' '))

Num = namedtuple("Num","ind x")

bucket = defaultdict(Num)

for i, a in enumerate(arr):
    bucket[a][0] += 1
