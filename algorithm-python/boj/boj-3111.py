import sys

input = sys.stdin.readline

a = input().rstrip()
reva = a[::-1]
t = input().rstrip()
fi, ri = 0, len(t)-1
f_st = []
r_st = []
# 앞에서부터 넣기, 뒤에서부터 넣기
while fi <= ri:
    while fi <= ri:
        f_st.append(t[fi])
        fi += 1
        if len(f_st) >= len(a) and ''.join(f_st[-len(a):]) == a:
            del f_st[-len(a):]
            break
    while fi <= ri:
        r_st.append(t[ri])
        ri -= 1
        if len(r_st) >= len(a) and ''.join(r_st[-len(a):]) == reva:
            del r_st[-len(a):]
            break

all_st = f_st + r_st[::-1]
ti = 0
while ti >= 0:
    ti = ''.join(all_st).find(a)
    if ti != -1:
        del all_st[ti:ti+len(a)]
print(''.join(all_st))
