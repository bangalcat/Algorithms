import sys

# f = open('test.in','r')
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    root = [i for i in range(n + 1)]
    lens = [0] * (n+1)

    def find(u):
        if root[u] == u:
            return root[u]
        else:
            r = find(root[u])
            lens[u] += lens[root[u]]
            root[u] = r
            return root[u]

    def merge(u, v):
        lens[u] = abs(u - v) % 1000
        root[u] = v

    while True:
        line = input()
        if line.startswith('I'):
            c, i, j = line.rstrip().split(' ')
            merge(int(i), int(j))
        elif line.startswith('E'):
            c = int(line.rstrip().split(' ')[1])
            _ = find(c)
            print(lens[c])
        else:
            break
