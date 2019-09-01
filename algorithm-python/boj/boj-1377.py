# 버블 소트
import sys
n = int(input())
arr = [(i, input()) for i in range(n)]
new_arr = enumerate(sorted(arr, key=lambda x: int(x[1])))
max_move_elem = max(new_arr, key=lambda x: x[1][0] - x[0])
print(max_move_elem[1][0] - max_move_elem[0] + 1)

