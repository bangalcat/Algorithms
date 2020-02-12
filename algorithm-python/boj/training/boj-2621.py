# 카드게임

f = open('boj/training/test.in', 'r')
input = f.readline

if __name__ == "__main__":
    # 5개 카드
    shapes = []
    numbers = []
    check = [0] * 10
    for i in range(5):
        s, num = input().split()
        shapes.append(s)
        numbers.append(int(num))
        check[int(num)] += 1
    
    def solve() -> int:
        ret = max(numbers) + 100
        # 숫자 연속 체크
        sort_nums = sorted(numbers, reverse=True)
        prev = sort_nums[0]
        for i in sort_nums[1:]:
            if prev - i != 1:
                break
            prev = i
        else:
            if len(set(shapes)) == 1:
                return 900 + sort_nums[0]
            else:
                return 500 + sort_nums[0]
        # 같은 색 체크
        if len(set(shapes)) == 1:
            ret = max(ret, 600 + max(numbers))
        # 같은 숫자 체크
        if max(check) == 4:
            return check.index(4) + 800
        elif max(check) == 3:
            if 2 in check:
                return check.index(3) * 10 + check.index(2) + 700
            ret = max(ret, check.index(3) + 400)
        elif 2 in check:
            if check.count(2) == 2:
                fi = check.index(2)
                ret = max(ret, fi + check.index(2, fi + 1) * 10 + 300)
            else:
                ret = max(ret, check.index(2) + 200)

        return ret

    print(solve())