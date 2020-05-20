"""
ID: alexzha5
LANG: PYTHON3
TASK: palsquare
"""
with open('palsquare.in', 'r') as fin:
    base = int(fin.readline().strip())

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

fout = open('palsquare.out', 'w')
for i in range(1, 301):
    b = base_change(i * i, base)
    if is_pal(b):
        fout.write(base_change(i, base) + " " + b + "\n")
fout.close()
