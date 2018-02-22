#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long r, a, b, c, d;
    cin >> r >> a >> b >> c >> d;
    if ((a - c) * (a - c) + (b - d) * (b - d) >= r * r) {
        cout << a << ' ' << b << ' ' << r << '\n';
    }
    else  {
        double dr = hypot((double)a - c, (double)b - d);
        double ar = (r + dr) / 2.0;
        double x = (c - a) * ar / dr;
        double y = (d - b) * ar / dr;
        if (fabs(dr) < 1e-6) {
            x = -ar;
            y = 0;
        }
        printf("%.10lf %.10lf %.10lf\n", c - x, d - y, ar);
    }
}