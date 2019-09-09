from collections import Counter
# 정올 초등부 2004
# 로마 숫자

rome_dic = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000
}
a = input()
b = input()
alist = [rome_dic[a[x]] for x in range(len(a))]
blist = [rome_dic[b[x]] for x in range(len(b))]
def conv(nums):
    ret = 0
    prev = 0
    for i in nums:
        if prev and prev < i:
            ret += (i - prev*2)
        else:
            ret += i
        prev = i
    return ret

def conv_s(num):
    # for example, num = 2493
    ret = ''
    ctr = Counter()
    while num:
        if num >= 1000 and ctr['M'] < 3:
            num -= 1000
            ctr['M'] += 1
            ret += 'M'
        elif num >= 900:
            num -= 900
            ctr['CM'] += 1
            ret += 'CM'
        elif num >= 500 and ctr['D'] < 1:
            num -= 500
            ctr['D'] += 1
            ret += 'D'
        elif num >= 400 and ctr['CM'] < 1 and ctr['CD'] < 1:
            num -= 400
            ctr['CD'] += 1
            ret += 'CD'
        elif num >= 100:
            num -= 100
            ctr['C'] += 1
            ret += 'C'
        elif num >= 90 and ctr['XC'] < 1:
            num -= 90
            ctr['XC'] += 1
            ret += 'XC'
        elif num >= 50 and ctr['L'] < 1:
            num -= 50
            ctr['L'] += 1
            ret += 'L'
        elif num >= 40 and ctr['XC'] < 1 and ctr['XL'] < 1:
            num -= 40
            ctr['XL'] += 1
            ret += 'XL'
        elif num >= 10:
            num -= 10
            ctr['X'] += 1
            ret += 'X'
        elif num >= 9 and ctr['IX'] < 1 and ctr['IV'] < 1:
            num -= 9
            ctr['IX'] = 9
            ret += 'IX'
        elif num >= 5 and ctr['V'] < 1:
            num -= 5
            ctr['V'] += 1
            ret += 'V'
        elif num >= 4 and ctr['IX'] < 1 and ctr['IV'] < 1:
            num -= 4
            ctr['IV'] += 1
            ret += 'IV'
        else:
            num -= 1
            ctr['I'] += 1
            ret += 'I'
    return ret

sums = conv(alist) + conv(blist)
print(sums)
print(conv_s(sums))
