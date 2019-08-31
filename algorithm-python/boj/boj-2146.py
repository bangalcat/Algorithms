
f = open('test.in','r')
input = f.readline
n = int(input())
board = [[int(x) for x in input().split(' ')] for _ in range(n)]
INF = 300
def numbering(board, sr, sc, number):
    q = [(sr, sc)]
    board[sr][sc] = number
    while q:
        r, c = q.pop(0)
        adj = [
            (r+1, c), (r, c+1), (r-1, c), (r, c-1)
        ]
        for nr, nc in adj:
            if 0 <= nr < n and 0 <= nc < n:
                if board[nr][nc] == 1:
                    board[nr][nc] = number
                    q.append((nr, nc))

def find_bridge(board, sr, sc):
    discovered = [[0] * n for _ in range(n)]
    q = [(sr, sc)]
    discovered[sr][sc] = 1
    number = board[sr][sc]
    while q:
        r, c = q.pop(0)
        if discovered[r][c] - 1 > short_dist:
            return INF
        adj = [
            (r+1, c), (r, c+1), (r-1, c), (r, c-1)
        ]
        for nr, nc in adj:
            if 0 <= nr < n and 0 <= nc < n and not discovered[nr][nc]:
                if board[nr][nc] == 0:
                    discovered[nr][nc] = discovered[r][c] + 1
                    q.append((nr, nc))
                elif board[nr][nc] != number:
                    return discovered[r][c] - 1
    return INF


number = 2
for i in range(n):
    for j in range(n):
        if board[i][j] == 1:
            numbering(board, i, j, number)
            number += 1

short_dist = INF
for i in range(n):
    for j in range(n):
        if board[i][j] > 1:
            short_dist = min(short_dist, find_bridge(board, i, j))

print(short_dist)
