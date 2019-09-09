# dp
# boj-1495 기타리스트 문제와 유사. 각 항목에서 더하거나 빼거나
n = int(input())
numlist = [int(x) for x in input().split()]
eq_cnt = [[0] * 21 for _ in range(n + 1)]

eq_cnt[0][numlist[0]] = 1

for i in range(1, n-1):
    for j in range(21):
        if eq_cnt[i-1][j]:
            if j - numlist[i] >= 0:
                eq_cnt[i][j - numlist[i]] += eq_cnt[i-1][j]
            if j + numlist[i] <= 20:
                eq_cnt[i][j + numlist[i]] += eq_cnt[i-1][j]

ret = eq_cnt[n-2][numlist[-1]]

print(ret)
