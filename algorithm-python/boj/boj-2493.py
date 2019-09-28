# 탑
# 이분탐색인줄 알았지만? 저번에 풀어보라고 주셨던 문제와 비슷한 느낌의 문제


def solve():
    def inputs():
        n = int(input())
        nlist = [int(x) for x in input().split()]
        return n, nlist

    n, nlist = inputs()
    qlist = [(-1, 0)]
    ret = []
    for i, h in enumerate(nlist):
        if qlist and qlist[-1][0] >= h:
            ret.append(qlist[-1][1])
            qlist.append((h, i+1))
        else:
            while qlist[-1][0] != -1 and qlist[-1][0] < h:
                qlist.pop()
            if qlist:
                ret.append(qlist[-1][1])
                qlist.append((h, i+1))
    print(*ret)


if __name__ == '__main__':
    solve()
