# 왼쪽 회전 = 수 증가(그 다음 모든 수들)
# 오른쪽 회전 = 수 감소(자신만)
# 왼쪽 회전은 다음 수에 더할 수들을 누적
def solve():
    n = int(input())
    curr_state = input().strip()
    target_state = input().strip()
    retlist = [[0] * 2 for _ in range(n)]

    dp = {}

    def func(ind, accum):
        # print(ind)
        if ind == n: return 0
        if (ind, accum) in dp: return dp[ind, accum]
        # min(좌, 우)
        l = (20 + int(target_state[ind]) - accum - int(curr_state[ind])) % 10
        r = 10 - l
        lret = func(ind + 1, (accum + l) % 10) + l
        rret = func(ind + 1, accum) + r
        # retlist[ind][0] = l
        # retlist[ind][1] = r
        dp[ind, accum] = min(lret, rret)
        return min(lret, rret)

    print(func(0, 0))
    ret = []
    def reconstruct():
        accum = 0
        for i in range(n):
            if func(i, accum) == func(i+1, accum + retlist[i][0]) + retlist[i][0]:
                ret.append((i, retlist[i][0]))
            else:
                ret.append((i, -retlist[i][1]))
    # print(retlist)
    # reconstruct()
    # for i, p in ret:
    #     if p != 0:
    #         print(i+1, p)

if __name__ == '__main__':
    solve()
