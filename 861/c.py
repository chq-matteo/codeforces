from sys import stdin, stdout
s = list(stdin.readline().strip())
vowels = set('aeiou')
r = []
cons = 0
v = set()
for c in s:
    if c in vowels:
        cons = 0
        v.clear()
        r.append(c)
    else:
        cons += 1
        v.add(c)
        if cons >= 3 and len(v) >= 2:
            r.append(' ')
            cons = 1
            v.clear()
            v.add(c)
        r.append(c)
        
        
stdout.write(''.join(r))
stdout.write('\n')