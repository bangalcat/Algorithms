n = int(input())

c = 0
cnt = 1
ans = 0
while n > c:
    if not (n - c) % cnt:
        ans += 1
    c += cnt
    cnt += 1

print(ans)
