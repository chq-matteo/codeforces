from sys import stdin, stdout
import math
n, m = [int(x) for x in stdin.readline().split()]
c = []
for i in range(m):
    c.append([int(x) for x in stdin.readline().split()])
p = set()
for a in range(1, 101):
    t = True
    for k in c:
        t = t and k[0] <= k[1] * a and (k[0] > ((k[1] - 1) * a))
    if t:
        p.add(int(math.ceil(n / a)))
if len(p) == 1:
    stdout.write('{}\n'.format(p.pop()))
else:
    stdout.write('-1\n')
