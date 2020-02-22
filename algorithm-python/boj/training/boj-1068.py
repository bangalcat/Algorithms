# 트리
from collections import defaultdict
if __name__ == "__main__":
    n = int(input())
    parents = list(map(int, input().split()))
    dnode = int(input())
    childs = defaultdict(list)
    root = 0
    for i in range(n):
        if i != dnode:
            childs[parents[i]].append(i)
        if parents[i] == -1:
            root = i
    
    def count_leaf(node):
        ret = 0
        if not childs[node]:
            return 1
        for ch in childs[node]:
            ret += count_leaf(ch)
        return ret
    
    print(count_leaf(root) if root != dnode else 0)