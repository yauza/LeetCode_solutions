

def binarySearch(nums, x):
    l = 0
    r = len(nums)-1
    while l <= r:
        mid = (l+r)//2
        if nums[mid] == x:
            return True
        elif nums[mid] > x:
            r = mid-1
        else:
            l = mid+1

    return False



def searchMatrix(matrix, target):
    j = 0
    while j < len(matrix)-1 and target > matrix[j][0]:
        if j+1 < len(matrix) and target < matrix[j+1][0]:
            break
        else:
            j+=1



    return binarySearch(matrix[j], target)





matrix = [[2, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
print(searchMatrix([[]], 34))