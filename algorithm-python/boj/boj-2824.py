# 최대공약수
# 큰 두 수의 최대공약수. 파이썬은 biginteger가 int형에서 자동으로 알아서 처리됨
from functools import reduce
from math import gcd
n = input()
nlist = map(int, input().split())
m = input()
mlist = map(int, input().split())
A = reduce(lambda x,y : x * y, nlist)
B = reduce(lambda x,y : x * y, mlist)
answer = str(gcd(A,B))
print(answer[-min(len(answer),9):])