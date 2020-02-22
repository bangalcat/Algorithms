# 분수 합

def gcd(a, b):
    if a < b:
        return gcd(b, a)
    return b if a % b == 0 else gcd(b, a % b)
if __name__ == "__main__":
    a1, a2 = map(int, input().split())
    b1, b2 = map(int, input().split())
    c1 = a1 * b2 + a2 * b1
    c2 = a2 * b2
    g = gcd(c1, c2)
    c1, c2 = c1 / g, c2 / g
    print(int(c1), int(c2))