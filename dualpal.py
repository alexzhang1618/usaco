"""
ID: alexzha5
LANG: PYTHON3
TASK: dualpal
"""
with open('dualpal.in', 'r') as fin:
    n, s = map(int, fin.readline().strip().split())

def base_change(num, base):
    """Change ``num'' to given base
    Upto base 36 is supported."""

    converted_string, modstring = "", ""
    currentnum = num
    if not num:
        return '0'
    while currentnum:
        mod = currentnum % base
        currentnum = currentnum // base
        if chr(48 + mod + 7 * (mod > 10)) == ":":
            converted_string = "A" + converted_string
        else:
            converted_string = chr(48 + mod + 7 * (mod > 10)) + converted_string
    return converted_string

def is_pal(a):
    return a[::-1] == a

fout = open('dualpal.out', 'w')
num = s
while(n != 0):
    counter = 2
    s += 1
    for i in range(2, 11):
        b = base_change(s, i)
        if(is_pal(b)):
            counter -= 1
            if counter == 0:
                fout.write(str(s) + "\n")
                n -= 1
                break
fout.close()
