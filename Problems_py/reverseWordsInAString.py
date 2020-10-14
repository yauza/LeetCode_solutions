
def solve(s):
    arr = s.split(" ")
    print(arr)
    res = ""
    n = len(arr)
    i = 0
    while i < n:
        if arr[i] == "":
            arr.pop(i)
            i -= 1
            n -= 1
        i += 1
    print(arr)
    for i in range(len(arr)-1, -1, -1):
        print(i)
        if i != 0:
            res += (arr[i] + " ")
        else:
            res += arr[i]
    return res

s = "the sky is blue"
s1 = "halo    kurwa"
s2 = "   kerwix dupa   "
print(solve(s2))