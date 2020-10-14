
def solve(nums):
    n = len(nums)
    i = 1
    while i < n:
        print(nums, i)
        if nums[i] == nums[i - 1]:
            n -= 1
            nums.pop(i)
            i -= 1
        i += 1
    print(nums)
    return n

nums = [0,0,1,1,1,2,2,3,3,4]
nums1 = [1,1,2]
print(solve(nums1))