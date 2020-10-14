

def solve(secret, guess):
    dict = {}

    for i in range(len(secret)):
        if dict.get(secret[i]) is None:
            dict[secret[i]] = [i]
        else:
            dict[secret[i]].append(i)
    print(dict)

    b, c = 0, 0
    for i in range(len(guess)):
        #print(secret[i])
        if guess[i] in dict:
            if len(dict[guess[i]]) > 1:
                x = 0
                for el in dict[guess[i]]:
                    if el == i:
                        b += 1
                        x = 1
                        break
                if x == 1:
                    continue
                else:
                    c += 1
            else:
                if dict[guess[i]][0] == i:
                    b += 1
                else:
                    c +=1

    res = (str(b)+"A"+str(c)+"B")

    return res


def solve1(secret, guess):
    b, c = 0, 0
    n = len(secret)
    i = 0
    while i < n:
        # print(secret, guess, b)
        if secret[i] == guess[i]:
            b += 1
            secret = secret[:i] + secret[i+1:]
            guess = guess[:i] + guess[i + 1:]
            i -= 1
        i += 1
        n = len(secret)

    countS = [0]*10
    countG = [0]*10

    for i in range(len(secret)):
        countS[int(secret[i])] += 1
        countG[int(guess[i])] += 1

    for i in range(len(countS)):
        if countS[i] != 0 and countG[i] != 0:
            c += min(countS[i], countG[i])

    res = (str(b)+"A"+str(c)+"B")

    return res

s = "1807"
g = "7810"
print(solve1(s, g))    #1A3B

secret = "1123"
guess = "0111"
print(solve1(secret, guess))    #1A1B

s1 = "0000"
g1 = "1000"
print(solve1(s1, g1))    #3A0B
