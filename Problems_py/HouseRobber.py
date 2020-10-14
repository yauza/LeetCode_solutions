
def solve(nums):
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return nums[0]
    dp = [float("-inf")]*len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, len(nums)):
        dp[i] = max(dp[i-1], dp[i-2]+nums[i])

    return dp[len(nums)-1]



nums = [1, 2, 3, 1]
print(solve(nums))
#Output: 4

nums1 = [2,7,9,3,1]
print(solve(nums1))
#output: 12

nums2 = [2,1,1,9,8,1,1,3]
print(solve(nums2))
#output: 15

nums3 = [1,2]
print(solve(nums3))
#output: 2