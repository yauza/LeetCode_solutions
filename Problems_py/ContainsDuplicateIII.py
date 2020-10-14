
def containsNearbyalmostDuplicate(nums, k, t):         #TLE na 40/41

    dict = {}

    if len(nums) < 2 or k == 0:
        return False

    for i in range(len(nums)):
        dict[i] = nums[i]
    print(dict)
    for el in dict:
        #print("el: ", el)
        for i in range(1, k+1):
            if abs(el - i) == el:
                break
            x = dict.get(abs(el - i))
            # print("x: ", x, " dict[el]: ", dict[el], " i: ", i)
            if x == None:
                continue
            if abs(x - dict[el]) <= t:
                return True

    return False


def containsNearbyalmostDuplicateBUCKETSORT(nums, k, t):
    n = len(nums)

    if n == 0 or k < 0 or t < 0:
        return False

    buckets = {}
    temp = t+1

    for i, v in enumerate(nums):
        b = v // temp

        if b in buckets:
            return True
        else:
            buckets[b] = v
            if (b-1 in buckets and v-buckets[b-1] <= t) or(b+1 in buckets and buckets[b+1]-v <= t):
                return True

            if i >= k:
                del buckets[nums[i-k] // temp]


    return False



A = [1, 2, 3, 1]
B = [1, 0, 1, 1]
C = [1, 5, 9, 1, 5, 9]
D = [1]
E = [5, 9]
F = [-3, 3]
G = [-10, 15, 20]
H = [1, -3, 100, 14, 20, -2, 8]
print(containsNearbyalmostDuplicateBUCKETSORT(A, 3, 0))
print(containsNearbyalmostDuplicateBUCKETSORT(B, 1, 2))
print(containsNearbyalmostDuplicateBUCKETSORT(C, 2, 3))
print(containsNearbyalmostDuplicateBUCKETSORT(D, 1, 1))
print(containsNearbyalmostDuplicateBUCKETSORT(E, 1, 5))
print(containsNearbyalmostDuplicateBUCKETSORT(F, 2, 4))
print(containsNearbyalmostDuplicateBUCKETSORT(G, 2, 4))
print(containsNearbyalmostDuplicateBUCKETSORT(H, 2, 5))




