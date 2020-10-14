

class Node:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def searchTree(node, array):
    if not node:
        return
    if node.left:
        searchTree(node.left, array)
    array.append(node.val)
    if node.right:
        searchTree(node.right, array)

def mergeArrays(t1,t2):
    t3 = []

    i = 0
    j = 0
    while i < len(t1) and j<len(t2):
        if t1[i] < t2[j]:
            t3.append(t1[i])
            i += 1
        else:
            t3.append(t2[j])
            j += 1
    while i < len(t1):
        t3.append(t1[i])
        i += 1
    while j < len(t2):
        t3.append(t2[j])
        j += 1
    return t3


def getAllElements(root1, root2):
    t1 = []
    searchTree(root1, t1)
    print(t1)

    t2 = []
    searchTree(root2, t2)
    print(t2)
    return mergeArrays(t1,t2)

a = Node(5)
b = Node(2)
c = Node(9)
a.left = b
a.right = c

d = Node(10)
e = Node(1)
f = Node(11)
d.left = e
d.right = f

print(getAllElements(a, d))