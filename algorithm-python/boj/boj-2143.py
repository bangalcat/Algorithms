import sys
from collections import defaultdict

f = open("test.in", "r")
input = f.readline


# input = sys.stdin.readline

def solve():
    T = int(input())
    n = int(input())
    alist = list(map(int, input().rstrip().split(' ')))
    m = int(input())
    blist = list(map(int, input().rstrip().split(' ')))

    a_sum_list = []
    for i in range(n):
        temp = 0
        for j in alist[i:]:
            temp += j
            a_sum_list.append(temp)

    b_sum_cnt_map = defaultdict(int)
    for i in range(m):
        temp = 0
        for j in blist[i:]:
            temp += j
            b_sum_cnt_map[temp] += 1

    cnt = 0
    for a in a_sum_list:
        if T-a in b_sum_cnt_map.keys():
            cnt += b_sum_cnt_map[T-a]
    print(cnt)


solve()

f.close()
