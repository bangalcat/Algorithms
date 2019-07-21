def solve(n, s):
    ret = ""
    for i in s :
        ret += i*n
    return ret

t = int(input())
for i in range(t):
    r, s = input().split(' ')
    print(solve(int(r), s))
