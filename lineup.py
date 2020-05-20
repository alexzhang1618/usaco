"""
ID: alexzha5
LANG: PYTHON3
TASK: lineup
"""

fin = open('lineup.in', 'r')
lineup = ["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
appearance = {i:0 for i in lineup}
lineup.sort()
constraints = []
final = []
lst = []
n = int(fin.readline().strip())

for i in range(n):
    constraints.append(fin.readline().strip().split(" must be milked beside "))

for i in constraints:
    for j in i:
        appearance[constraints[j]] += 1
        if appearance[constraints[j]] == 2:
            lst.append[constraints[j]]


if max(appearance.values()) == 2:
    a = None
    for i in lst:
        for j in constraints:
            if i in j and a:
                a = j
                constraints.remove(j)
            elif i in j:
                a += j
                a.remove(i)
                a.remove(i)
                a.sort()
                a.insert(i, 1)
                for k in a:
                    lineup.remove(k)
                lineup.append(tuple(a))
                constraints.remove(j)
for i in constraints:
    i.sort()
    lineup.remove(i[0])
    lineup.remove(i[1])
    lineup.append(tuple(i))

lineup.sort()

for i in lineup:
    final.extend(i)
with open('lineup.out', 'w') as fout:
    for i in final:
        fout.write(str(i) + "\n")
