from collections import defaultdict

n = int(input())
wlist = list(map(int, input().split(' ')))
wlist.append(0)
m = int(input())
mlist = map(int, input().split(' '))

cache = [defaultdict(bool) for _ in range(31)]

# 현재 만들어진 무게, 현재 curInd번째 추 사용차례.
# cache에 기록하면서 전체 추 개수만큼 3^30 (pruning)
def preCheck(currInd, currWeight):
    if currInd > n:
        return

    if cache[currInd][currWeight]:
        return

    cache[currInd][currWeight] = True

    # cache는 n까지 기록되어야함. wlist는 n-1까지 존재.
    preCheck(currInd + 1, currWeight + wlist[currInd])
    preCheck(currInd + 1, currWeight)
    preCheck(currInd + 1, abs(currWeight - wlist[currInd]))


preCheck(0, 0)
ans = []
for mb in mlist:
    ans.append('Y' if mb <= n*500 and cache[n][mb] else 'N')

print(*ans)
