import sys
input = sys.stdin.readline

n = int(input())
st = []
ret = 0
for _ in range(n):
    curr = int(input())
    same = 0
    while st and st[-1][0] <= curr:
        ret += st[-1][1]
        if st[-1][0] == curr:
            same += st[-1][1]
        st.pop()
    if st:
        ret += 1
    st.append((curr, same+1))

print(ret)

