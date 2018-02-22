from sys import stdin, stdout
from collections import deque
i, w, n, m, x0, y0, c, d, k, e = [int(x) for x in stdin.readline().split()]
walls = set()
doors = set()
keys = set()
exits = set()
maze = [[0 for j in range(m)] for ii in range(n)]
for r in range(c):
    x1, y1, x2, y2 = [int(x) for x in stdin.readline().split()]
    walls.add(tuple(sorted([x1, x2]) + sorted([y1, y2])))

for r in range(d):
    x1, y1, x2, y2 = [int(x) for x in stdin.readline().split()]
    doors.add(tuple(sorted([x1, x2]) + sorted([y1, y2])))
    
for r in range(k):
    x1, y1 = [int(x) for x in stdin.readline().split()]
    keys.add(tuple([x1, y1]))
for r in range(e):
    x1, y1 = [int(x) for x in stdin.readline().split()]
    exits.add(tuple([x1, y1]))
dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]
nat = ['down', 'right', 'up', 'left']

def can(x, y, d):
    if tuple(sorted([x, x + d[0]]) + sorted([y, y + d[1]])) in walls:
        return False
    if x + d[0] < 0 or x + d[0] >= n or y + d[1] < 0 or y + d[1] >= m or visited[x + d[0]][y + d[1]] != False:
        return False
    return True
visited = [[False for j in range(m)] for ii in range(n)]
visited[x0][y0] = (x0, y0)
def bfs():
    q = deque()
    q.append(tuple([x0, y0]))
    while len(q) > 0:
        x, y = q.popleft()
        if (x, y) in exits:
            # backtrace
            bt = deque()
            xx, yy = x, y
            while visited[xx][yy] != (xx, yy):
                bt.appendleft((xx, yy))
                xx, yy = visited[xx][yy]
            x, y = x0, y0
            for i in range(len(bt)):
                xx, yy = bt.popleft()
                print('move-{}'.format(nat[dirs.index((xx - x, yy - y))]))
                x, y = xx, yy
            return
        for j, v in enumerate(dirs):
            if can(x, y, v):
                q.append(tuple([x + v[0], y + v[1]]))
                visited[x + v[0]][y + v[1]] = (x, y)
bfs()