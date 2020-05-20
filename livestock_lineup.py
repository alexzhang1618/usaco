"""
ID: alexzha5
LANG: PYTHON3
TASK: lineup
"""
names = ["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
cows = []
finder = {}
order = []
class Cow:
  def __init__(self, name):
      self.name = name
      left = 0
      constraints = []
      used = False

def first_cow(cows):
    """
    returns the first cow that should be picked
    """
    for i in cows:
        if not used and len(constraints) < 2:
            i.used = True
            return i

def next_cow(cow):
    """
    returns index of next cow that should be picked given last cow
    """
    for i in cow.constraints:
        if not finder[i].used:
            finder[i].used = True
            return finder[i]

fin = open('lineup.in', 'r')
n = int(fin.readline().strip())
for i in names:
    a = Cow(names[i])
    cows.append(a)
for i in range(len(names)):
    finder[names[i]] = i
for i in range(n):
    a, b = fin.readline().strip().split(" must be milked beside ")
    cows[finder[a]].constraints.append(b)
    cows[finder[b]].constraints.append(a)
    cows[finder[a]].left += 1
    cows[finder[b]].left += 1

order[0] = cows[first_cow(cows)]
for i in range(1, 8):
    if order[i - 1].left == 0:
        order[i] = cows[first_cow(cows)]
    else:
        order[i] = cows[next_cow(order[i - 1])]
        order[i].left -= 1
        order[i - 1].left -= 1

with open('lineup.out', 'w') as fout:
    for i in order:
        fout.write(i + "\n")
