
#unfinished
def printtab(arr):
    for i in arr:
        print(i)


def solve(k, n):
    dp = [[0]*k for i in range(n)]
    printtab(dp)
    digits = [1, 2, 3, 4, 5, 6, 7, 8, 9]



k = 3
n = 9
solve(k, n)