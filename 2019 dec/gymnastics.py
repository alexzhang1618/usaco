"""
ID: alexzha5
LANG: PYTHON3
TASK: gymnastics
"""
def search(a, b):
    for i in range(len(a)):
        if a[i] == b:
            return i
    return 0

fin = open('gymnastics.in', 'r')
k, n = map(int, fin.readline().split())
count = 0
greater = {}
less = {}
for i in range(k):
    rank = [i for i in map(int, fin.readline().split())]
    if i == 0:
        for x in range(1, n):
            for y in range(x + 1, n + 1):
                if(rank.index(x) < rank.index(y)):
                    greater[(x, y)] = True
                    less[(x, y)] = False
                else:
                    greater[(x, y)] = False
                    less[(x, y)] = True
    else:
        for x in range(1, n):
            for y in range(x + 1, n + 1):
                if(rank.index(x) < rank.index(y)):
                    greater[(x, y)] = greater[(x, y)] and True
                    less[(x, y)] = less[(x, y)] and False
                else:
                    greater[(x, y)] = greater[(x, y)] and False
                    less[(x, y)] = less[(x, y)] and True
for i in greater.values():
    if i:
        count += 1
for i in less.values():
    if i:
        count += 1
with open('gymnastics.out', 'w') as fout:
    fout.write(str(count) + "\n")
