import bisect



def solve(intervals, newInterval):

    i = 0
    n = len(intervals)
    start, end = newInterval[0], newInterval[1]
    res = []
    res.append(intervals[0])
    for i in range(1, n):
        if intervals[i-1][1] < newInterval[0] < newInterval[1] < intervals[i][0]:
            res.append(newInterval)
        res.append(intervals[i])
    if len(res) != len(intervals):
        return res
    else:
        res = []

    i = 0

    while i < n:
        if intervals[i][0] == intervals[i][1]+1:
            i += 1
        if intervals[i][1] > newInterval[0] > intervals[i][0]:
            start = intervals[i][0]
            break
        i += 1
    #if start == -1:

    while i < n:
        print(intervals[i][0], newInterval[1], intervals[i][1])
        if intervals[i][0] == intervals[i][1]+1:
            i += 1
        if intervals[i][0] < newInterval[1] < intervals[i][1]:
            end = intervals[i][1]
            break
        i += 1


    #res = []
    i = 0
    for i in intervals:
        if start > i[1]:
            res.append(i)
        if end < i[0]:
            res.append(i)
        if start >= i[0] and start <= i[1]:
            res.append([start, end])

    return res


def solve1(intervals, newInterval):
    l, r = [], []

    for i in intervals:
        if i[1] < newInterval[0]:
            l.append(i)
        elif i[0] > newInterval[1]:
            r.append(i)
        else:
            newInterval[0] = min(newInterval[0], i[0])
            newInterval[1] = max(newInterval[1], i[1])

    return l + [[newInterval[0], newInterval[1]]] + r





intervals = [[1,3],[6,9]]
newInterval = [2,5]
#Output: [[1,5],[6,9]]

intervals1 = [[1,2],[4,6],[7,9],[10,11],[14,17]]
newInterval1 = [5,15]
#Output: [[1,2],[4,17]]

intervals2 = [[0,1],[2,3]]
newInterval2 = [0,6]
#Output: [[0,6]]

intervals3 = [[0,1],[7,8]]
newInterval3 = [2,6]
#Output: [[0,1],[2,6],[7,8]]
print(solve1([[1,5]], [4,8]))
