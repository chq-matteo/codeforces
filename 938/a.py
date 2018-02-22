from sys import stdout, stdin

n = int(stdin.readline())
s = stdin.readline().strip()
vw = False
vowels = set('aeiouy')
ans = []
for c in s:
    if not (c in vowels and vw):
        ans.append(c)
    if c in vowels:
        vw = True
    else:
        vw = False
stdout.write(''.join(ans))
stdout.write('\n')