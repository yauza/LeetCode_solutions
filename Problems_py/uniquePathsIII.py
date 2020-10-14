res = 0
counter = 1

def recursion(grid, i, j):
    global counter
    if i > 0 and j > 0 and i < len(grid) and j < len(grid) and grid[i][j] != -1:
        if grid[i][j] == 2:
            if counter == 0:
                global res
                res += 1
            return

        grid[i][j] = -1
        counter -= 1

        recursion(grid, i+1, j)
        recursion(grid, i-1, j)
        recursion(grid, i, j+1)
        recursion(grid, i, j-1)

        grid[i][j] = 0
        counter += 1
    else:
        return





def rec(grid, i, j):
    global counter
    if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[i]) or grid[i][j] == -1:
        return
    #print(counter, grid[i][j])
    if grid[i][j] == 2:
        if counter == 0:
            global res
            res += 1
        return

    grid[i][j] = -1
    counter -= 1

    rec(grid, i+1, j)
    rec(grid, i-1, j)
    rec(grid, i, j+1)
    rec(grid, i, j-1)

    counter += 1
    grid[i][j] = 0



def uniquePathsIII(grid):
    n, m = len(grid[0]), len(grid)
    global counter
    counter = 1
    res = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                startX = i
                startY = j
            if grid[i][j] == 0:
                counter += 1

    rec(grid, startX, startY)

    ans = res
    return ans

grid = [[1,0,0,0],    #4
        [0,0,0,0],
        [0,0,0,2]]

print(uniquePathsIII(grid))