# Problem A
We have to answer to 'given 4 integers l, r, x, y and given an integer k, are there any two integers a, b such that k = a/b, l <= a <= r and x <= b <= y?'.  
Since l, r, x, y are small we can check for every b in [x, y] if l <= k*b = a <= r
# Problem B
We have to answer if a circle C lies completely in an annolus.  
We just need to check if the distance between C and the center of the inner circle (d) minus the radius of C (r) is more than the radius of the inner circle (ri) and d + r is less than the radius of the outer circle (ro).  
To avoid issues with floating point arithmetic, we can rewrite d - r >= ri as d >= ri + r and then square both sides since they are both positive and then rewrite d + r <= ro as d <= ro - r if ro - r is negative then the inequality is false otherwise we can square both sides.  
![two concentric circles and C, d+r in red, d-r in blue](b.png)
# Problem C
Wrong for now