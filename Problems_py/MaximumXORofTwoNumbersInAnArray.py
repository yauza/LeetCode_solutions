#in cpp


def solve(nums):
    for i in range(len(nums)):
        for j in range(len(nums)):
            print(nums[j], "^", nums[i], ":",nums[j] ^ nums[i])

nums = [3, 10, 5, 25, 2, 8]
solve(nums)