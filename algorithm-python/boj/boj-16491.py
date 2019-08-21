from math import hypot
from itertools import permutations


# 벡터로 표현하고, 모든 선분이 겹치지 않도록 선분 그리기
class Vector:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return isinstance(other, Vector) and other.x == self.x and other.y == self.y

    def __add__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x + other.x, self.y + other.y)
        elif isinstance(other, int):
            return Vector(self.x + other, self.y + other)

    def __sub__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x - other.x, self.y - other.y)
        elif isinstance(other, int):
            return Vector(self.x - other, self.y - other)

    def __lt__(self, other):
        return self.x < other.x if self.x != other.x else self.y < other.y

    def __mul__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x * other.x, self.y * other.y)
        elif isinstance(other, int):
            return Vector(self.x * other, self.y * other.y)

    # sqrt(x**2 + y**2)
    def norm(self):
        return hypot(self.x, self.y)

    def normalize(self):
        r = self.norm()
        return Vector(self.x / r, self.y / r)

    def dot(self, other) -> float:
        return self.x * other.x + self.y * other.y

    def cross(self, other) -> float:
        return self.x * other.y - self.y * other.x

    # 사영
    def project(self, other):
        r = other.normalize()
        return r * r.dot(self)


def ccw(a, b, o=Vector(0, 0)) -> float:
    """
    :return:
       점 o를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수
       평행이면 0 return
       o는 default 값으로 (0,0)
    """
    return (a - o).cross(b - o)


# 겹쳐있는지
def cc(a, b, c):
    return min(a.x, b.x) <= c.x <= max(a.x, b.x) and \
           min(a.y, b.y) <= c.y <= max(a.y, b.y)


def segmentIntersects(a, b, c, d) -> bool:
    """
        선분 ab와 cd가 교차하는지 간단하게
    :return:
    """
    ab = ccw(b, c, a) * ccw(b, d, a)
    cd = ccw(d, a, c) * ccw(d, b, c)
    # 두 직선이 한 직선 위 or 끝점 겹치는 경우
    if ab == 0 and cd == 0:
        if b < a: a, b = b, a
        if d < c: c, d = d, c
        return not (b < c or d < a)
    return ab <= 0 and cd <= 0


if __name__ == '__main__':
    f = open('test.in','r')
    input = f.readline
    n = int(input())
    robots = [Vector(*map(float, input().split(' '))) for _ in range(n)]
    shelters = [Vector(*map(float, input().split(' '))) for _ in range(n)]

    def existIntersect(st_indlist):
        for p_i in range(n):
            for q_i in range(p_i+1, n):
                if segmentIntersects(robots[p_i], shelters[st_indlist[p_i]-1],
                                     robots[q_i], shelters[st_indlist[q_i]-1]):
                    return True
        return False

    for st_list in permutations(range(1, n+1)):
        if not existIntersect(st_list):
            print(*st_list, sep='\n')
            break

