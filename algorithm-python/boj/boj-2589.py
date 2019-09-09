# 정올 초등부 2004
# 무식하게 bfs로 찾는 문제
h, w = map(int, input().split(' '))
tmap = []
for _ in range(h):
    tmap.append(input())

def isrange(r, c, h, w):
    return 0 <= r < h and 0 <= c < w

# 1,0,-1,0 // 0,-1,0,1
# bfs all
def get_max_route(sr, sc, tmap):
    # start from sr, sc to all possible cell
    q = [(sr, sc)]
    max_path = 0
    discovered = [[-1]*w for _ in range(h)]
    discovered[sr][sc] = 0
    while q:
        hr, hc = q.pop(0)
        max_path = max(discovered[hr][hc], max_path)
        next_list = [
            (hr+1, hc), (hr, hc-1), (hr-1, hc), (hr, hc+1)
        ]
        for nr, nc in next_list:
            if isrange(nr, nc, h, w) and discovered[nr][nc] is -1 and tmap[nr][nc] != 'W':
                q.append((nr, nc))
                discovered[nr][nc] = discovered[hr][hc] + 1

    return max_path

ans = 0
for r in range(h):
    for c in range(w):
        if tmap[r][c] == 'L':
            ans = max(ans, get_max_route(r, c, tmap))

print(ans)
