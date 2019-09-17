board = [[int(x) for x in input().split()] for _ in range(5)]
call = [[int(x) for x in input().split()] for _ in range(5)]

dic = {board[i][j]: (i, j) for i in range(5) for j in range(5)}

def bingo_count():
    cnt = 0
    for line in board:
        if sum(line) == 0:
            cnt += 1
    for line in list(map(list, zip(*board))):
        if sum(line) == 0:
            cnt += 1
    cnt += sum([board[i][i] for i in range(5)]) == 0
    cnt += sum(board[i][4-i] for i in range(5)) == 0
    return cnt >= 3

def solve():
    for i in range(5):
        for j in range(5):
            ii, jj = dic[call[i][j]]
            board[ii][jj] = 0
            if bingo_count():
                print(i * 5 + j + 1)
                return True

solve()
