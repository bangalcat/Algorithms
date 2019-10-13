# 두번 뒤집기
# 정올 초등부 문제

import copy

def reverse(arr, start, end, step):
    ret = []
    arr_c = copy.deepcopy(arr) # deepcopy로 reverse 조작해가면서 실행
    for t in range(start, end+step, step):
        if arr_c[t-1] != t:
            for i in range(t-1, end+step, step): # 원래 위치 찾으면 거기까지 뒤집어버리기
                if arr_c[i] == t:
                    ret.append((t, i+1))
                    arr_c[t-1:i+step:step] = list(reversed(arr_c[t-1:i+step:step]))
                    # print(arr_c)
                    break
            else: # 뒤에서부터 본다고 쳤을때, 0번 index까지 보려면 까다롭다. 그냥 for-else로 처리
                ret.append((1, t))
                arr_c[:t] = list(reversed(arr_c[:t]))
    return ret if len(ret) <= 2 else []


if __name__ == '__main__':
    n = int(input())
    nlist = [int(x) for x in input().split()]
    ret = reverse(nlist, 1, n, 1)
    if not ret: # 앞으로 돌려서 답없으면 뒤에서부터 보기
        ret = reverse(nlist, n, 1, -1)
    while len(ret) < 2:
        ret.append((1, 1))
    for p in ret:
        print(*sorted(p))


