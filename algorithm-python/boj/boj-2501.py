def solve():
    n, k = map(int, input().split())
    ll = []
    for i in range(1, n+1):
        if n % i == 0:
            ll.append(i)
            if len(ll) == k:
                return ll[-1]
    return 0

if __name__ == '__main__':
    print(solve())
