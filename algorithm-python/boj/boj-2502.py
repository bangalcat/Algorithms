def solve(d, k):
    a = [1, 0, 1]
    b = [0, 1, 1]
    for i in range(3, 31):
        a.append(a[-1] + a[-2])
        b.append(b[-1] + b[-2])

    # print(*zip(a,b))
    # a[d] * A + b[d] * B = k
    for i in range(1, 1000):
        if (k - a[d-1] * i) % b[d-1] == 0:
            return i, (k - a[d-1] * i) // b[d-1]
    assert False

if __name__ == '__main__':
    d, k = map(int, input().split())
    print(*solve(d, k), sep='\n')

