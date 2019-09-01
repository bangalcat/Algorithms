# 기하문제
# 원의 둘레
import sys
from collections import namedtuple
import math

PI: float = 3.141592653589793
Vector = namedtuple('Vector', ['x', 'y'])

if __name__ == '__main__':
    for line in sys.stdin:
        x1, y1, x2, y2, x3, y3 = map(float, line.split(' '))
        v1, v2, v3= Vector(x1,y1), Vector(x2, y2), Vector(x3, y3)
        l1 = Vector(x2-x1, y2-y1)
        l2 = Vector(x3-x2, y3-y2)
        l3 = Vector(x1-x3, y1-y3)
        s = abs((l1.x * l2.y - l1.y * l2.x) / 2)
        r = math.hypot(l1.x, l1.y) * math.hypot(l2.x, l2.y) * math.hypot(l3.x, l3.y) / (4 * s)
        ans = r * 2 * PI
        print(round(ans, 2))
