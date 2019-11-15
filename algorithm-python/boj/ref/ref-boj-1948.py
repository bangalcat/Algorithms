import sys, collections
input = sys.stdin.readline
print = sys.stdout.write


def topological_sorting():
    q = collections.deque()
    d[start_node] = 0
    q.append((start_node, d[start_node]))

    while q:
        c_node, c_cost = q.popleft()

        for n_node, n_cost in v[c_node]:
            ind[n_node] -= 1

            d[n_node] = max(d[n_node], d[c_node] + n_cost)

            if ind[n_node] == 0:
                q.append((n_node, d[n_node]))


def reverse_topological_sorting():
    check = [False] * (n+1)
    q = collections.deque()
    q.append((end_node, d[end_node]))
    check[end_node] = True

    while q:
        c_node, c_cost = q.popleft()
        for n_node, n_cost in rv[c_node]:
            rind[n_node] -= 1

            if check[c_node] and d[n_node] == d[c_node] - n_cost:
                check[n_node] = True
                global cnt
                cnt += 1

            if rind[n_node] == 0:
                q.append((n_node, d[n_node]))


n = int(input())
m = int(input())
cnt = 0

v = [[] for _ in range(n+1)]
rv = [[] for _ in range(n+1)]
ind = [0] * (n+1)
rind = [0] * (n+1)
d = [0] * (n+1)


for _ in range(m):
    a, b, c = map(int, input().split())
    v[a].append((b, c))
    rv[b].append((a, c))

    ind[b] += 1
    rind[a] += 1

start_node, end_node = map(int, input().split())

topological_sorting()
reverse_topological_sorting()

print("%d\n" % d[end_node])
print("%d\n" % cnt)
