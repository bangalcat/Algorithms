# 카드
# 최빈값 중 최소값 찾기
from collections import defaultdict, Counter

n = int(input())
nmap = defaultdict(int)
for _ in range(n):
    a = int(input())
    nmap[a] += 1

ans = max(nmap.items(), key=lambda x: (x[1], -x[0]))
print(ans[0])
######## Counter 이용한 쉬운방법 ##########
import sys

input()
counter = Counter(sys.stdin)
sys.stdout.write(str(max(counter, key=lambda x: (counter[x], -int(x)))))
