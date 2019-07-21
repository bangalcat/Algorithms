
def solution(strings, n) :
    return sorted(strings, key=lambda x:x[n-1])

n = int(input())
strings = input().split()

print(solution(strings,n))
