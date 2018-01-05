from sys import stdin, stdout
a, b = [int(x) for x in stdin.readline().strip().split()]

x, y, z = [int(w) for w in stdin.readline().strip().split()]

A = 2 * x + y
B = 3 * z + y

stdout.write('{}\n'.format(max(0, A - a) + max(0, B - b)))