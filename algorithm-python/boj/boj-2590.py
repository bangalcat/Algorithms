"""
    백준 : 색종이 문제
    인터넷 코드 그대로 써먹으려다 다수 실패. #2번에서 2번 블록이 9로 나눠떨어지는 경우에 대해선 예외처리 해줬어야함
"""
block_cnt = [int(input()) for _ in range(6)]
ret = block_cnt[3] + block_cnt[4] + block_cnt[5] # 4, 5, 6번 색종이 한판씩
# 5번 색종이에 1번 색종이 11장
block_cnt[0] -= 11 * block_cnt[4]
# 4번
block_cnt[1] -= block_cnt[3] * 5
# 3번
if block_cnt[2]:
    ret += (block_cnt[2]-1) // 4 + 1
    block_cnt[2] %= 4
if block_cnt[2]:
    block_cnt[0] -= 8 - block_cnt[2]
    block_cnt[1] -= 7 - 2 * block_cnt[2]
# 2
if block_cnt[1] > 0:
    ret += (block_cnt[1]-1) // 9 + 1
    if block_cnt[1] % 9:
        block_cnt[0] -= 36 - block_cnt[1] % 9 * 4
else:
    block_cnt[0] += block_cnt[1] * 4
# 1
if block_cnt[0] > 0:
    ret += (block_cnt[0] - 1) // 36 + 1
print(ret)


