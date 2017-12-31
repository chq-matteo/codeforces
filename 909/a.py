from sys import stdin, stdout

a, b = stdin.readline().strip().split()
ans = a + b
for i in range(1, len(a) + 1):
    for j in range(1, len(b) + 1):
        c = a[:i] + b[:j]
        ans = min(c, ans)

stdout.write(ans + '\n')