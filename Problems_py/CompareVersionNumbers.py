
def solve(version1, version2):
    v1 = version1.split(".")
    v2 = version2.split(".")
    print(v1, v2)
    if len(v1) > len(v2):
        for i in range(len(v1)-len(v2)):
            v2.append("0")
    elif len(v1) < len(v2):
        for i in range(len(v2)-len(v1)):
            v1.append("0")

    for i in range(len(v1)):
        v1[i] = int(v1[i])
        v2[i] = int(v2[i])
    print(v1, v2)

    # for i in range(len(v1)):
    #     if v1[i] > v2[i]:
    #         return 1
    #     elif v2[i] > v1[i]:
    #         return -1

    for i, j in zip(v1, v2):
        if i > j:
            return 1
        elif i < j:
            return -1

    return 0





v1 = "1.0.1"
v2 = "1"

v3 = "2.0.0.1"
v4 = "2.0.1"

v5 = "1"
v6 = "1.1"

# print(solve(v1, v2))
# print(solve(v3, v4))
print(solve(v5, v6))