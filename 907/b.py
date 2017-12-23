# x is the first player
# even number of chips means it is the first player turn
# odd number of chips means it is the second player turn
from sys import stdin, stdout

b = stdin.readlines()

x, y = [int(z) for z in b[-1].strip().split()]

m = [list(l) for l in b[:-1]]
# get in which smaller board we have to play
pos_x, pos_y = (x - 1) % 3, (y - 1) % 3
# print pos_x, pos_y

# check if there are any free spots
free = 0
for i in range(4 * pos_x, 4 * pos_x + 3):
    for j in range(4 * pos_y, 4 * pos_y + 3):
        if m[i][j] == '.':
            free += 1
            m[i][j] = '!'

if free == 0:
    for l in m:
        stdout.write(''.join(l).replace('.', '!'))
else:
    for l in m:
        stdout.write(''.join(l))
stdout.write('\n')