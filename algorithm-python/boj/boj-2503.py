from itertools import permutations

def solve():
    l = [str(x) for x in range(1, 10)]
    n = int(input())
    game = []
    for _ in range(n):
        num, s, b = input().split()
        game.append((num, int(s), int(b)))

    def is_pass(num):
        for g in game:
            s, b = 0, 0
            for i, j in zip(num, g[0]):
                if i == j: s += 1
            if num[0] in (g[0][1], g[0][2]):
                b += 1
            if num[1] in (g[0][0], g[0][2]):
                b += 1
            if num[2] in (g[0][1], g[0][0]):
                b += 1
            if (s, b) != (g[1], g[2]):
                return False
        return True
    cnt = 0
    for ll in permutations(l, 3):
        if is_pass(ll):
            cnt += 1
    return cnt

if __name__ == '__main__':
    print(solve())
