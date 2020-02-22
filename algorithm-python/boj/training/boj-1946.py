# 신입사원
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        nlist = []
        count = 0
        for i in range(n):
            a, b = map(int, input().split())
            nlist.append((a, b))
        nlist = sorted(nlist)
        m = n+1
        for a, b in nlist:
            if b < m:
                m = b
                count += 1
        print(count)
                
            