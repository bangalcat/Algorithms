# f = open('test.in','r')
# input = f.readline

N, d, k, c = map(int, input().split(' '))
sushi = [int(input()) for _ in range(N)]
bucket = [0] * (d+1)
start, end = 0, k - 1
ans, type_cnt = 0, 0
for s in sushi[:k]:
    bucket[s] += 1
    if bucket[s] == 1: type_cnt += 1
bucket[c] += 1
if bucket[c] == 1: type_cnt += 1
ans = type_cnt
while start < N:
    bucket[sushi[start]] -= 1
    if bucket[sushi[start]] == 0:
        type_cnt -= 1
    start += 1
    end = (end + 1) % N
    bucket[sushi[end]] += 1
    if bucket[sushi[end]] == 1:
        type_cnt += 1
    ans = max(ans, type_cnt)

print(ans)

