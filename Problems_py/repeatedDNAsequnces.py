



def findRepeatedDnaSequences(s):
    dict = {}
    res = []

    for i in range(len(s)-9):
        print(s[i:i+10])
        if s[i:i+10] in dict:
            dict[s[i:i+10]] += 1
            if dict[s[i:i+10]] > 2:
                continue
            else:
                res.append(s[i:i+10])
        else:
            dict[s[i:i+10]] = 1

    return res




s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
s1 = "AAAAAAAAAAA"
print(findRepeatedDnaSequences(s1))