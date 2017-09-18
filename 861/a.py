from sys import stdin, stdout
n, k = [int(x) for x in stdin.readline().split()]
def gcd(a, b):
    if a%b == 0:
        return b
    else:
        return gcd(b, a%b)
stdout.write('{}'.format(n // gcd(n, 10**k) * 10**k))
