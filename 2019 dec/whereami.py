"""
ID: alexzha5
LANG: PYTHON3
TASK: whereami
"""
with open('whereami.in', 'r') as fin:
    num = int(fin.readline().strip())
    char = fin.readline().strip()

def f(s, n = 1):
    for i in range(num - n):
        if(s.count(s[i:i+n]) > 1):
            return f(s, n+1)
    return n

with open('whereami.out', 'w') as fout:
    fout.write(str(f(char)) + '\n')
