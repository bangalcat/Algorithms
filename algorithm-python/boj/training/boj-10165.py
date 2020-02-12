f = open('algorithm-python/boj/training/test.in', 'r')
input = f.readline

import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    lines = []
    kmax = 0
    for i in range(m):
        a, b = map(int, input().split())
        if a > b:
            kmax = max(kmax, b)
            b += n
        lines.append((a, b, i + 1))
    lines = sorted(lines, key=lambda x: (x[0], -x[1]))
    dq = []
    for i in lines:
        if not dq or dq[-1][1] < i[1]:
            dq.append(i)
    while dq and dq[0][1] <= kmax:
        dq.pop(0)
    dq = sorted(dq, key=lambda x: x[2])
    for _, _, k in dq:
        print(k, end=' ')
