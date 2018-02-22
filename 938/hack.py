# n^2 log n worst case for who doesn't prune queue
print('200000 199999')
for i in range(0, 199999):
    print('200000 {} {}'.format(i + 1, 2 * (i + 1)))
l = list(range(1, 400000, 2))[::-1]
l[-1] = 10**12
print(' '.join([str(x) for x in l]))