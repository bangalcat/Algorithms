import re

T = int(input())
pattern = re.compile('^(100+1+|01)+$')
for _ in range(T):
    sig = input()
    m = pattern.match(sig)
    ans = 'YES' if m else 'NO'
    print(ans)
