import sys
import collections
f = open("test.in","r")
input = f.readline

n = int(input())
adjlist = collections.defaultdict(list)
for i in range(n):
    alist = [int(x)-1 for x in input().split(' ')][1:]
    adjlist[i] = alist

team = {}

for i in range(n):
    if i in team.keys():
        continue
    team[i] = 1
    que = [i]
    while que:
        curr = que.pop()
        for hater in adjlist[curr]:
            if hater not in team.keys():
                que.append(hater)
                team[hater] = 3 - team[curr]
ateam = sorted([k+1 for k, v in team.items() if v == 1])
bteam = sorted([k+1 for k, v in team.items() if v == 2])

print(len(ateam))
print(*ateam)
print(len(bteam))
print(*bteam)

