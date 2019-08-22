# 중앙값 구하기

import heapq

f = open('test.in', 'r')
input = f.readline

T = int(input())
for _ in range(T):
    n = int(input())
    nums = []
    for i in range(int(n/10) + 1):
        nums += [int(x) for x in input().split(' ')]
    lq = []
    rq = []
    ans = []
    ans_temp = []
    for num in nums:
        # 두 큐의 사이즈 같으면 무조건 오른쪽큐로 push만
        # 오른쪽 큐가 더 크면 오른쪽 top과 비교해서 더 작은것이 왼쪽으로, 큰것은 오른쪽으로 -> 일단 오른쪽에 push하고 사이즈 2차이나면 왼쪽으로 하나 옮기기
        if lq and -lq[0] > num:
            heapq.heappush(rq, -heapq.heapreplace(lq, -num))
        else:
            heapq.heappush(rq, num)
        if len(rq) > len(lq) + 1:
            heapq.heappush(lq, -heapq.heappop(rq))
        else:
            ans_temp.append(rq[0])
            if len(ans_temp) == 10:
                ans.append(ans_temp)
                ans_temp = []
    if ans_temp:
        ans.append(ans_temp)
    print(sum([len(s) for s in ans]))
    for line in ans:
        print(*line)
