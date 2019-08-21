from math import hypot


# ccw 판단
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
        1: ccw / -1 : cw / 0 : colline
       점 o를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수
       평행이면 0 return
       o는 default 값으로 (0,0)
    """
    return (a - o).cross(b - o)


if __name__ == '__main__':
    plist = [Vector(*map(float, input().split(' '))) for _ in range(3)]
    k = ccw(plist[1],plist[2],plist[0])
    if k > 0:
        print(1)
    elif k < 0:
        print(-1)
    else:
        print(0)

