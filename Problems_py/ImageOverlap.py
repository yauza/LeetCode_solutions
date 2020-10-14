def imageOverlap(A, B):
    n = len(A)
    res = [[0]*(2*n-1) for i in range(2*n-1)]

    for i in range(n):
        for j in range(n):
            if A[i][j]:
                for a in range(n):
                    for b in range(n):
                        if B[a][b]:
                            res[a-i][b-j] += 1
    print(res)
    maxi = 0
    for i in res:
        for j in i:
            maxi = max(maxi, j)

    return maxi




A = [[1,1,0],
     [0,1,0],
     [0,1,0]]
B = [[0,0,0],
     [0,1,1],
     [0,0,1]]

print(imageOverlap(A, B))
