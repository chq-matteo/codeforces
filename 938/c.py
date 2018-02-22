from sys import stdin, stdout
from math import sqrt
def factor(x):
    for i in range(1, int(sqrt(x)) + 2):
        if x % i == 0 and x // i >= i:
            yield i

t = int(stdin.readline())
for i in range(t):
    x = int(stdin.readline())
    if x == 0:
        stdout.write('1 1\n')
        continue
    found = False
    for k in factor(x):
        # k = a - b
        q = x // k
        a = (k + q) // 2
        b = q - a
        if 1 <= a <= 10 ** 9 and 1 <= b <= 10 ** 9 and a >= b:
            stdout.write('{} {}\n'.format(a, b))
            found = True
            break
    if not found:
        stdout.write('-1\n')