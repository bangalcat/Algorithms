class Vector:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def __eq__(self, other):
        return isinstance(other, Vector) and other.x == self.x and other.y == self.y

    def __lt__(self, other):
        return self.x < other.x if self.x != other.x else self.y < other.y

    def __sub__(self, other):
        if isinstance(other, Vector):
            return Vector(self.x - other.x, self.y - other.y)
        elif isinstance(other, int):
            return Vector(self.x - other, self.y - other)
        else:
            raise TypeError

    def cross(self, other) -> float:
        return self.x * other.y - self.y * other.x

    def __str__(self):
        return '{0},{1}'.format(str(self.x), str(self.y))


if __name__=='__main__':
    n = int(input())
    vlist = [Vector(*map(int, input().rstrip().split(' '))) for _ in range(n)]
    o = vlist[0]
    print(round(abs(sum((vlist[i]-o).cross(vlist[i+1] - o) for i in range(1,n-1)))/2, 1))

