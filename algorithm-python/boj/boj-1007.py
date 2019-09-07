# 벡터 매칭
# 단순 조합 탐색
from itertools import combinations
T = int(input())
for _ in range(T):
    n = int(input())
    sum_x, sum_y = 0.0, 0.0
    vectors = []
    for i in range(n):
        x, y = map(int, input().split(' '))
        sum_x += x
        sum_y += y
        vectors.append((x,y))
    ret = 10**7
    for comb in combinations(vectors, n//2):
        rx = sum_x - 2 * sum([x[0] for x in comb])
        ry = sum_y - 2 * sum([x[1] for x in comb])

        ret = min(((rx**2) + (ry**2)) ** 0.5, ret)
    print(ret)
