import sys

def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a%b)
n, k = [int(x) for x in sys.stdin.readline().split()]
m = 1
n += 1
can = True
for i in range(2, k + 1):
    # print(gcd(m, i))
    m = m * i // gcd(m, i)
    if m > n or n % m != 0:
        can = False
        break
# print m
if can:
    sys.stdout.write('Yes\n')
else:
    sys.stdout.write('No\n')
    