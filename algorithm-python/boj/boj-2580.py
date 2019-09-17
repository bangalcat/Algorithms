# 스도쿠
def cell(r, c): return (r // 3) * 3 + c // 3

check_row = [[False] * 10 for _ in range(10)]
check_col = [[False] * 10 for _ in range(10)]
check_cell = [[False] * 10 for _ in range(10)]

board = [[int(x) for x in input().split()] for _ in range(9)]
for i in range(9):
    for j in range(9):
        check_row[i][board[i][j]] = True
        check_col[i][board[j][i]] = True
        check_cell[cell(i, j)][board[i][j]] = True

def play():
    r, c = -1, -1
    for i in range(9):
        find = False
        for j in range(9):
            if board[i][j] == 0:
                r, c = i, j
                find = True
                break
        if find: break

    if r < 0:
        for line in board:
            print(*line)
        return True

    for num in range(1, 10):
        if not (check_row[r][num] or check_col[c][num] or check_cell[cell(r,c)][num]):
            board[r][c] = num
            check_row[r][num] = True
            check_col[c][num] = True
            check_cell[cell(r, c)][num] = True
            if play():
                return True
            board[r][c] = 0
            check_row[r][num] = False
            check_col[c][num] = False
            check_cell[cell(r, c)][num] = False

    return False

play()
