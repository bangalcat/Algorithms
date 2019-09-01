import math

PI = 2.0 * math.acos(0.0)
class Vector:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        return self.x < other.x if self.x != other.x else self.y < other.y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def norm(self):
        return math.hypot(self.x, self.y)

    def __sub__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x - other.x, self.y - other.y)
        elif isinstance(other, int):
            return Vector(self.x - other, self.y - other)

    def cross(self, other):
        """ 외적"""
        return self.x * other.y - other.x * self.y

    def __str__(self):
        return '({}, {})'.format(self.x, self.y)

def ccw(a, b, o=Vector(0, 0)) -> float:
    """
    :return:
       점 o를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수
       평행이면 0 return
       o는 default 값으로 (0,0)
    """
    return (a - o).cross(b - o)

def gift_wrap(plist:list):
    plist = list(enumerate(plist))
    hull = []
    pivot = plist[0]
    hull.append(pivot)
    while True:
        ph, nxt = hull[-1][1], plist[0]
        elist = []  # 지워지는 중간점
        for p in plist[1:]:
            cr = ccw(nxt[1], p[1], ph)
            dist = (nxt[1] - ph).norm() - (p[1]-ph).norm()
            if cr > 0:
                nxt = p
                elist = []
            elif cr == 0 and dist < 0:
                elist.append(nxt)
                nxt = p
            elif cr == 0 and dist > 0:
                elist.append(p)

        if nxt == pivot: break
        if elist:
            for tp in elist:
                hull.append(tp)
        hull.append(nxt)
    return hull

def chunker(seq, size):
    return (seq[pos:pos+size] for pos in range(0,len(seq),size))

if __name__=='__main__':
    t = int(input())
    for _ in range(t):
        line = list(map(int, input().split(' ')))
        n = line[0]
        plist = []
        for x, y in chunker(line[1:], 2):
            plist.append(Vector(x, y))
        hull = gift_wrap(plist)
        print(*[x[0] for x in hull], sep=' ')


