# 수학
# 조합 0의 개수

def count_base(number, b):
    cnt = 0
    i = b
    while number // i:
        cnt += (number // i)
        i *= b
    return cnt

n, m = map(int, input().split(' '))

five_cnt = count_base(n, 5) - count_base(n-m, 5) - count_base(m, 5)
two_cnt = count_base(n, 2) - count_base(n-m, 2) - count_base(m, 2)
print(min(five_cnt, two_cnt))
