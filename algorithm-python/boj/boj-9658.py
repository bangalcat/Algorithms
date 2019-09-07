dp = [[-1] * 1001 for _ in range(2)]
def play(turn, remain):
    # return : win(True) or lose(False)
    if remain == 0:
        return True
    if dp[turn][remain] != -1:
        return dp[turn][remain]
    dp[turn][remain] = 0
    for a in [4, 3, 1]:
        if remain >= a and not play(1 - turn, remain - a):
            dp[turn][remain] = 1
            return True
    return False

n = int(input())
if play(0, n):
    print('SK')
else:
    print('CY')
