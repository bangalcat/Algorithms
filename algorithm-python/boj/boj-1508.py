
f = open('test.in', 'r')
input = f.readline

(n, m, k) = map(int, input().split(' '))
plist = list(map(int, input().split(' ')))
# plist.append(n)
plist = sorted(plist)


def decision(gap, print):
    limit = -1
    cnt = 0
    for x in plist:
        if limit < x and cnt < m:
            cnt += 1
            limit = x + gap
            if print:
                print(1, end='')
        else:
            if print:
                print(0, end='')
    return cnt >= m


lo = 0
hi = n + 1
while lo + 1 < hi:
    mid = int((lo + hi) / 2)
    if decision(mid, None):
        lo = mid
    else:
        hi = mid
decision(lo, print)

f.close()
