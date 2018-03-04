from sys import stdin, stdout
import math
import decimal as dm

k, d, t = [int(x) for x in stdin.readline().split()]
dm.getcontext().prec = 200
dc = (dm.Decimal(k) / dm.Decimal(d)).quantize(dm.Decimal('1'), rounding=dm.ROUND_CEILING) * dm.Decimal(d)
segp = (dc + dm.Decimal(k)) / dm.Decimal(2 * t)
segt = dc
nseg = (dm.Decimal(1.0) / segp).quantize(dm.Decimal('1'), rounding=dm.ROUND_FLOOR)
# print(nseg, segp)
dt = nseg * segt

p = dm.Decimal(1) - nseg * segp
# print(p)
kseg = min(p, dm.Decimal(k) / dm.Decimal(t))
# print(kseg)
dt += kseg * dm.Decimal(t)

p -= kseg
dt += p * dm.Decimal(2 * t)
stdout.write('{:.10}\n'.format(dt))