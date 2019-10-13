n = 4
k = 23
perm = []

def factl(n):
    return factl(n-1) * n if n else 1

for d in range(n):
    digit = 1
    f = factl(n - d - 1)
    while k > f or digit in perm:
        if digit not in perm:
            k -= f
        digit += 1
    perm.append(digit)

print(perm)

