# 암호 코드 문제
# dp의 조건 이해
n = input()
if n[0] == '0':
    print(0)
else:
    dp = [0] * 5001
    dp[0] = 1
    prev_c = 0
    for i, _c in enumerate(n):
        i += 1
        c = int(_c)
        dp[i] = (dp[i] + (dp[i-1] if 1 <= c <= 9 else 0) + (dp[i-2] if 10 <= 10 * prev_c + c <= 26 else 0)) % 1000000
        prev_c = c
    print(dp[len(n)])

