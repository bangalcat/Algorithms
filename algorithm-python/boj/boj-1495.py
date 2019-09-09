# dp
# 백준 : 기타리스트
# 0 ~ M
# check[N][M] N번째 곡에서 volume M이 가능한지
# 1차원 dp로는 해결이 안되는 문제. 각각의 곡 볼륨을 빼거나 더하거나 모두 세어줘야 하기 때문에, 2^N 경우의수 발생.
N, S, M = map(int, input().split())
vlist = [0] + [int(x) for x in input().split()]
check = [[False] * (M + 1) for _ in range(N + 1)]

check[0][S] = True
ans = -1
for i in range(1, N+1):
    can_go = False
    for vol in range(M+1):
        if check[i-1][vol]:  # vol이 가능하다면
            if vol - vlist[i] >= 0:
                check[i][vol - vlist[i]] = True
                can_go = True
            if vol + vlist[i] <= M:
                check[i][vol + vlist[i]] = True
                can_go = True
    if not can_go:
        break

for vol in range(M, -1, -1):
    if check[N][vol]:
        ans = vol
        break

print(ans)
