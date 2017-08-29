import random
print(200000)
print(' '.join([str(i+1) for i in range(200000)]))
for i in range(2, 200000+1):
    print('{} {}'.format(i, random.randint(1, i-1)))