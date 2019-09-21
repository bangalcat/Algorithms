N, T = map(int, input().split())
# arr[][2] 시간 k 배점 s
arr = [[int(x) for x in input().split()] for _ in range(N)]

dp_score = [0] * 1000001
for k, s in arr:
    for t in range(T, 1, -1):
        if t - k >= 0:
            dp_score[t] = max(dp_score[t], dp_score[t - k] + s)
print(dp_score[T])



