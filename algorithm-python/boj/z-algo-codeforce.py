import sys
input = sys.stdin.readline

def zalgo(s = ''):
    L = R = 0
    n = len(s)
    for i in range(n):
        if i > R:
            L = R = i
            while R < n and s[R-L] == s[R]:
                R += 1
            z[i] = R - L
            R -= 1
        else:
            k = i - L
            if z[k] < R - i + 1:
                z[i] = z[k]
            else:
                L = i
                while R < n and s[R-L] == s[R]:
                    R += 1
                z[i] = R - L
                R -= 1

s = input().rstrip()
z = [0] * len(s)
zalgo(s)
ret = maxz = 0
n = len(z)
for i in range(n):
    if z[i] == n - i and maxz >= n - i:
        ret = i
        break
    maxz = max(maxz, z[i])

print(s[ret:] if ret else 'Just a legend')
