n, b = map(int, input().split(' '))
t = []
while n:
    t.append(n % b)
    n //= b
t.reverse()
l = ''.join([chr(i - 10 + ord('A')) if i >= 10 else str(i) for i in t])
print(l)

def conv(number, base):
    T = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    i, j = divmod(number, base)

    if i==0:
        return T[j]
    else:
        return conv(i, base) + T[j]
