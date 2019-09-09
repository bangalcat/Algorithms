from collections import Counter

n = int(input())
org = input()
org_c = Counter(org)
ans = 0
for i in range(n-1):
    comp_c = Counter(input())
    l = org_c - comp_c
    r = comp_c - org_c
    if sum(l.values()) <= 1 and sum(r.values()) <= 1:
        ans += 1
print(ans)
