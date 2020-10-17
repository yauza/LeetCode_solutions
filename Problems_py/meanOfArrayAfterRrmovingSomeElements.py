
def trimMean(arr):
    arr.sort()
    pr = (len(arr)/100)*5
    print(pr)
    pr = (int)(pr)
    print(pr)
    arr = arr[pr:len(arr)-pr]
    print(arr)
    mean = 0
    for i in arr:
        mean += i

    return float(mean/len(arr))


arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
arr1 = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
arr2 = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
print(trimMean(arr2))