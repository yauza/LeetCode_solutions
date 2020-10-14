
def largestTimeFromDigits(A):
    temp = [0]*10
    res = ""
    for i in range(4):
        temp[A[i]] += 1
    if temp[0] == 0 and temp[1] == 0 and temp[2] == 0:
        return res
    if temp[4] > 3 or temp[3] > 3 or temp[5] > 3 or temp[6] > 2 or temp[7] > 2 or temp[8] > 2 or temp[9] > 2:
        return res
    check = 0
    for i in range(6, 10):
        if temp[i] > 0:
            check += temp[i]

    if check > 2:
        return res

    if temp[6] == 2 or temp[7] == 2 or temp[8] == 2 or temp[9] == 2:
        for i in range(1, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break
        if res != "0" or res != "1":
            return ""
    elif temp[4] == 3 or temp[5] == 3:
        for i in range(1, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break
        if res != "0" or res != "1":
            return ""
    elif temp[3] == 3:
        for i in range(2, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break
    else:
        for i in range(2, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break

    if res[0] == "2":
        for i in range(3, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break
    else:
        for i in range(9, -1, -1):
            if temp[i] > 0:
                res += str(i)
                temp[i] -= 1
                break

    res += ":"

    for i in range(5, -1, -1):
        if temp[i] > 0:
            res += str(i)
            temp[i] -= 1
            break

    for i in range(9, -1, -1):
        if temp[i] > 0:
            res += str(i)
            break

    if len(res) == 5:
        return res
    else:
        return ""

A = [1, 2, 3, 4]
B = [5, 5, 5, 5]
C = [1, 9, 2, 3]
D = [2, 4, 5, 5]
E = [0, 0, 0, 0]
F = [2, 0, 6, 6]
G = [2, 7, 0, 7]
H = [1, 0 ,1 ,1]
I = [2, 4, 4, 4]

print(largestTimeFromDigits(A))
print(largestTimeFromDigits(B))
print(largestTimeFromDigits(C))
print(largestTimeFromDigits(D))
print(largestTimeFromDigits(E))
print(largestTimeFromDigits(F))
print(largestTimeFromDigits(G))
print(largestTimeFromDigits(H))
print(largestTimeFromDigits(I))





