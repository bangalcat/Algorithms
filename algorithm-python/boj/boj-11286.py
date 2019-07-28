import heapq, sys
input = sys.stdin.readline
n = int(input())
heap = []
for i in range(n) :
    a = int(input())
    if a < 0:
        heapq.heappush(heap, (abs(a), a))
    elif a > 0:
        heapq.heappush(heap, (abs(a), a))
    elif heap:
        abs_a, a = heapq.heappop(heap)
        print(a)
    else:
        print(0)
