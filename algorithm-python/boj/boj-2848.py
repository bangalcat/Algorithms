f = open('test.in', 'r')
input = f.readline
import collections

n = int(input())
words = [input().rstrip() for _ in range(n)]
wordset = set(''.join(words))
adj = collections.defaultdict(list)
indegree = collections.defaultdict(int)
for i in range(n - 1):
    for j in range(i+1, n):
        for k in range(min(len(words[i]), len(words[j]))):
            if words[i][k] != words[j][k]:
                if words[j][k] in adj[words[i][k]]: break
                adj[words[i][k]].append(words[j][k])
                indegree[words[j][k]] += 1
                break
            elif k == min(len(words[i]), len(words[j]))-1 and len(words[j]) < len(words[i]):
                print('!')
                exit(0)

que = []
tot_cnt = len(wordset)
for c in wordset:
    if not indegree[c]:
        que.append(c)

ans = []
cannotans = 0
for _ in range(tot_cnt):
    if not len(que):
        print('!')
        exit(0)
    if len(que) > 1:
        cannotans = 1
    c = que.pop()
    ans.append(c)
    for nn in adj[c]:
        indegree[nn] -= 1
        if not indegree[nn]:
            que.append(nn)
if cannotans:
    print('?')
else:
    print(''.join(ans))
