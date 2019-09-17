nums = sorted([x for x in [int(input()) for _ in range(7)] if x % 2])
print(sum(nums) if nums else -1)
if nums:
    print(nums[0])
