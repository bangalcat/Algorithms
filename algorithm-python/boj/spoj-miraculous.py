import sys
if __name__ == '__main__':
    while True:
        line = input()
        # print('line:', line)
        if not line:
            break
        n, h, b, e = map(int, line.rstrip().split())
        nlist = [int(x) for x in input().rstrip().split()]
        dq = []
        ret = [0] * n
        # 자신보다 작을때까지 꺼내기
        for i, num in enumerate(nlist[b-1:e], b-1):
            # dq 차있으면
            if dq:
                # h보다 차이 커지는것 제거
                if dq[0][0] + h <= i:
                    dq.pop(0)
                while dq and dq[-1][1] >= num:
                    dq.pop()  # 자신보다 크거나 같으면 제거
            dq.append((i, num))
            ret[dq[0][0]] += 1
        print(*[x for x in ret[b-1:e]])

