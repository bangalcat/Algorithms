import sys
input = sys.stdin.readline
if __name__ == '__main__':
    MAXN = 500001
    m = int(input())
    fx = [0] + [int(x) for x in input().split()]
    st = [[0] * 20 for _ in range(MAXN)]
    for i in range(1, m+1):
        st[i][0] = fx[i]
    for j in range(1, 19):
        for i in range(1, m+1):
            st[i][j] = st[st[i][j-1]][j-1]
    q = int(input())

    for i in range(q):
        n, x = map(int, input().split())
        for j in range(18, -1, -1):
            if n >= 1 << j:
                x = st[x][j]
                n -= 1 << j
        print(x)


################### 정답 코드 ###############################

input = __import__('sys').stdin.readline
MIS = lambda: map(int,input().split())

m = int(input())
fk = [[0] + list(MIS())]
for i in range(19):
    L = fk[-1]
    fk.append([L[L[x]] for x in range(m+1)])
for i in range(int(input())):
    n, x = MIS()
    for bit in range(19):
        if n&1: x = fk[bit][x]
        n>>= 1
    print(x)

