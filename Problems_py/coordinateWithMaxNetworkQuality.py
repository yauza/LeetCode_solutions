import math


def bestCoordinate(towers, radius):
    if len(towers) == 0:
        return []
    elif len(towers) == 1:
        return [towers[0][0], towers[0][1]]

    dict = {}

    def checkRadius(t, r):
        ans = []
        for i in range(t[0]-r, t[0]+r+1):
            for j in range(t[1]-r, t[1]+r+1):
                if r >= math.sqrt(math.pow(t[0]-i,2)+math.pow(t[1]-j,2)):
                    ans.append([i,j])
        return ans

    c = 0
    for x,y,q in towers:
        points = checkRadius(towers[c], radius)
        c += 1
        for i,j in points:
            if (i,j) in dict:
                dict[(i,j)] += math.floor(q/(1+(math.sqrt(math.pow(x-i,2)+math.pow(y-j,2)))))
            else:
                dict[(i,j)] = math.floor(q/(1+(math.sqrt((math.pow(x-i,2))+(math.pow(y-j,2))))))

    res = []
    ans = 0
    for el in dict:
        ans = max(ans, dict[el])
        print(ans)

    for el in dict:
        if dict[el] == ans:
            res.append(el)

    res.sort()
    print(res)

    return [res[0][0],res[0][1]]

towers = [[1,2,5],[2,1,7],[3,1,9]]
radius = 2

towers1 = [[1,2,13],[2,1,7],[0,1,9]]
radius1 = 2
# print(bestCoordinate(towers1, radius1))

towers2 = [[10,8,27],[18,10,18],[18,8,41],[13,37,26],[49,24,27],[2,33,33],[31,42,41],[12,50,13],[20,41,12],[2,35,1],[0,0,28],[29,43,26],[16,3,1]]
r2 = 8
print(bestCoordinate(towers2, r2))