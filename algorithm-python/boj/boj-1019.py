# 백준 풀이법

def count_page(x, alist, point):
    while x:
        alist[x%10] += point
        x //= 10

page = int(input())
ans = [0] * 10
point = 1
start = 1
while start <= page:
    # make end 9
    while page % 10 != 9 and start <= page:
        count_page(page, ans, point)
        page -= 1

    if page < start:
        break

    # make start 0
    while start % 10 != 0 and start <= page:
        count_page(start, ans, point)
        start += 1

    start //= 10
    page //= 10

    for i in range(10):
        ans[i] += (page - start + 1) * point
    point *= 10

print(*ans)
