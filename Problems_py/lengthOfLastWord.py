
def solve(s):
    str = s.split(" ")
    str = str[::-1]
    print(str)
    for i in str:
        if i != "":
            return len(i)
    return 0

s = "Hello world"
s1 = " dupa elo pomelo xddd     hahah    "
s2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
s3 = ""
print(solve(s))
