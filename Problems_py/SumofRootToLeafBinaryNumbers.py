
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None, end=False):
        self.val = val
        self.left = left
        self.right = right
        self.end = end

def searchTree(node, array, s):
    if not node:
        return
    s += str(node.val)

    if node.left:
        searchTree(node.left, array, s)
    if node.right:
        searchTree(node.right, array, s)
    if node.end:
        array.append(s)


def sumRootToLeaf(root):
    arr = []
    str = ""
    searchTree(root, arr, str)
    print(arr)
    sum, x = 0, 0
    j = 0
    res = []
    for i, num in enumerate(arr):
        x, j = 0, len(num)-1
        y = 0
        print(num)
        while j >= 0:
            if num[j] == "1":
                x += pow(2, y)
            j -= 1
            y += 1
        res.append(x)
    print(res)
    for i in res:
        sum += i

    return sum



a = TreeNode(1)
b = TreeNode(1)
c = TreeNode(0)
d = TreeNode(0)
a.left = b
a.right = c
b.right = d
d.end = True
c.end = True

print(sumRootToLeaf(a))