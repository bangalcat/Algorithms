# 그래프 1
# 섬의 개수
import sys
sys.setrecursionlimit(100000)
def isrange(r, c, n, m):
    return 0 <= r < n and 0 <= c < m

dr = [1, 0, -1, 0, 1, 1, -1, -1]
dc = [0, 1, 0, -1, 1, -1, -1, 1]

while True:
    w, h = map(int, input().rstrip().split(' '))
    if w == h == 0: break
    board = [input().rstrip().split(' ') for _ in range(h)]
    visit = [[False] * w for _ in range(h)]

    def dfs(r, c):
        visit[r][c] = True
        for d in range(8):
            nr, nc = r+dr[d], c+dc[d]
            if isrange(nr, nc, h, w) and board[nr][nc] == '1' and not visit[nr][nc]:
                dfs(nr, nc)
    count = 0
    for r in range(h):
        for c in range(w):
            if board[r][c] == '1' and not visit[r][c]:
                count += 1
                dfs(r, c)
    print(count)
