# 주몽
f = open('algorithm-python/boj/training/test.in', 'r')
input = f.readline

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    nlist = sorted(map(int, input().rstrip().split()))
    l, r = 0, n-1
    ret = 0
    while l < r:
        nr = nlist[r]
        while l < r and nlist[l] + nr > m:
            r -= 1
            nr = nlist[r]
        if l < r and nlist[l] + nr == m:
            ret += 1
            r -= 1
        l += 1
        
    print(ret)
