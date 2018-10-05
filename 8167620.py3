n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
# n=len(a), a * b minimum, change a
# it should be like max a * min b 
sort_idx_b = sorted(range(n),key = lambda i : b[i])
sort_a = sorted(a)[::-1]
s = 0
j = 0
for i in sort_idx_b:
  s += b[i] * sort_a[j]
  j = j + 1
print(s)