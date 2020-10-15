


def rotate(nums, k):
    n = len(nums)
    if k > n:
        k = k%n

    j = n-1
    for i in range(n-k, n):
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
            j -= 1
        else:
            break

    j = n-k-1
    for i in range(n-k):
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
            j -= 1
        else:
            break

    j = n-1
    for i in range(n):
        if i < j:
            nums[i], nums[j] = nums[j], nums[i]
            j -= 1
        else:
            break



nums = [1,2,3,4,5,6,7]
k = 3
rotate(nums, k)
print(nums)