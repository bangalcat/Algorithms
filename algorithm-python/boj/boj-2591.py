# 정올 초등부 2005
# 카드 조합하는 dp문제
num = input()

dp = [0] * (len(num) + 2)

def recurfun(num, i):
    if i == 0:
        return 1
    if dp[i] > 0:
        return dp[i]
    ret = 0
    if int(num[i]) > 0:
        ret += recurfun(num, i - 1)
    if 10 <= int(num[i - 1:i + 1]) <= 34:
        ret += recurfun(num, i - 2)
    dp[i] = ret
    return ret


ans = recurfun('9' + num, len(num))
print(ans)
