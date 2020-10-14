
def solve(s):
    dict = {}

    for i in range(len(s)):
        temp = dict.get(s[i])
        if temp is None:
            dict[s[i]] = [i, i]
        else:
            dict[s[i]] = [dict[s[i]][0], i]

    print(dict)
    temp = [0, 0]
    start, end = 0, 0
    u = dict[s[0]]
    res = []
    str = ""

    for v in dict:
        print("start: ", start, " end: ", end, " dict[v][0]: ", dict[v][0], " dict[v][1]: ", dict[v][1])

        if dict[v][1] > end and dict[v][0] <= end:
            end = dict[v][1]
        elif dict[v][1] > end and dict[v][0] >= end:
            end = dict[v][1]
            start = dict[v][0]
        if end < dict[v][0]:
            str = s[start:end]
            res.append(str)
            start = end

    return res

s = "aabaabaccbbddede"

print(solve(s))

