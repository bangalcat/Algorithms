# 오큰수
import sys
input = sys.stdin.readline
if __name__ == "__main__":
    n = int(input())
    nlist = [int(x) for x in input().rstrip().split()]
    ans = []
    prevs = []
    # 뒤에서부터 본다
    for num in nlist[::-1]:
        while prevs and prevs[-1] <= num:
            prevs.pop()
        ans.append(prevs[-1] if prevs else -1)
        prevs.append(num)

    print(*ans[::-1])
