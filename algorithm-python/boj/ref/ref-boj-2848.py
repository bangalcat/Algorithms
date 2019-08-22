n = int(input())
a = [input() for _ in range(n)]
s = sorted(set(''.join(a)))
g = [[] for _ in range(len(s))]
d = [0] * len(s)
for i in range(n - 1):
    j = 0
    while j < len(a[i]) and j < len(a[i + 1]) and a[i][j] == a[i + 1][j]: j += 1
    if j == len(a[i]): continue
    if j == len(a[i + 1]):
        print('!')
        exit()
    g[s.index(a[i][j])].append(s.index(a[i + 1][j]))
    d[s.index(a[i + 1][j])] += 1
r = ''
f = False
for _ in range(len(s)):
    t = d.count(0)
    if not t:
        print('!')
        exit()
    if t > 1:
        f = True
    t = d.index(0)
    r += s[t]
    d[t] = -1
    for t in g[t]: d[t] -= 1
print('?' if f else r)