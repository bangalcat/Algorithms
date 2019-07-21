n = int(input())
vlist = sorted(map(int, input().split(' ')))

def solve(vlist) :
    if vlist[0] != 1 :
        return 1
    else:
        sum = 1
        for i in vlist[1:] :
            if sum + 1 < i :
                return sum + 1
            else:
                sum += i

        return sum + 1

print(solve(vlist))
