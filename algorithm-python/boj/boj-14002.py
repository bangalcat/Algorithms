# 가장 긴 증가하는 부분수열 4
# 부분수열의 구성까지 출력
# 역추적 방식 2가지
import bisect

def solve1():
    n = int(input())
    arr = [int(x) for x in input().strip().split()]
    C = []
    Cind = []
    parent = [-1] * n
    for i, num in enumerate(arr):
        if C and C[-1] >= num:
            ind = bisect.bisect_left(C, num)
            C[ind] = num
            Cind[ind] = i
            parent[i] = Cind[ind - 1] if ind > 0 else -1
        else:
            parent[i] = Cind[-1] if Cind else -1
            C.append(num)
            Cind.append(i)

    ret = [Cind[-1]]
    print(parent)
    while True:
        p = parent[ret[-1]]
        if p == -1: break
        ret.append(p)
    ret = [arr[i] for i in ret]
    print(len(C))
    print(*ret[::-1])

def solve2():
    n = int(input())
    arr = [int(x) for x in input().strip().split()]
    C = []
    p = []
    for num in arr:
        if C and C[-1] >= num:
            ind = bisect.bisect_left(C, num)
            C[ind] = num
            p.append((ind, num))
        else:
            p.append((len(C), num))
            C.append(num)

    ret = []
    t = len(C) - 1
    # print(p)
    for i, pnum in p[::-1]:
        if i == t:
            ret.append(pnum)
            t -= 1
        if t == -1: break

    print(len(C))
    print(*ret[::-1])

if __name__ == '__main__':
    solve1()

