# -2진법
# 수학
def conv(number):
    # if ?
    if number == 0:
        return ''
    # find k which is largest 2^k
    if number % -2:
        return conv((number - 1) // -2) + '1'
    else:
        return conv(number // -2) + '0'

n = int(input())
print(conv(n) if n else 0)

