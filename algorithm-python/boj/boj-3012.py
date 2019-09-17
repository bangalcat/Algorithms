# dp
# 올바른 괄호 문자열
# 모르겠다.. 답참고
# 범위 [시작, 끝]을 정해놓고 분할 탐색을 하며 적절한 쌍을 이루는지 파악
# 괄호가 명시된 경우 해당 괄호랑 쌍이지만 ?라면 모든 경우 대응가능
###########
n = int(input())
s = input()
cache = [[-1] * 201 for _ in range(201)]
op = "({["
cl = ")}]"

def f(start, end):
    if start > end: return 1

    if cache[start][end] != -1: return cache[start][end]

    ret = 0
    for i in range(start + 1, end + 1, 2):
        for j in range(3):
            if s[start] == op[j] or s[start] == '?':
                if s[i] == cl[j] or s[i] == '?':
                    # start와 짝이 맞는 괄호 위치 i
                    ret += f(start+1, i-1) * f(i+1, end)

    cache[start][end] = ret
    return ret

result = str(f(0, n-1))
print(result[-5:])
