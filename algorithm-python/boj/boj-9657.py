dp = [[-1] * 1001 for _ in range(2)]
def play(turn, remain):
    # return : win(False) or lose(True)
    if remain == 0:
        return True
    if dp[turn][remain] != -1:
        return dp[turn][remain]
    dp[turn][remain] = 1
    for a in [4, 3, 1]:
        if remain >= a and play(1 - turn, remain - a):
            dp[turn][remain] = 0
            return False
    return True

n = int(input())
if not play(0, n):
    print('SK')
else:
    print('CY')
