# 백준 NMK
# LIS로 푸는 문제가 아닌 LIS LDS를 만드는 문제.
# 그리디. 비둘기집의 원리로 증명
N, M, K = map(int, input().split())
if N < M + K - 1 or N > M * K:
    print(-1)
else:
    ret = [[i + 1] for i in range(M)]
    for num in range(M + 1, M + K):
        ret[0].append(num)
    group_i = 1
    for num in range(M + K, N + 1):
        ret[group_i].append(num)
        group_i = 1 + group_i % (M - 1)

    for gr in ret:
        print(*gr[::-1], end=' ')
