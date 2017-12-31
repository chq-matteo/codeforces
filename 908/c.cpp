// We only have 1000 disks so a O(n^2) solution is enough
// If two disk don't collide then the second disk can touch the end line
// If they do then we can compute y (position of center) using the condition of tangency for the two circles (distance = sum of radii)
#include <iostream>
#include <cmath>
using namespace std;
int x[1010];
double y[1010];
int main() {
    int n, r;
    cin >> n >> r;
    x[0] = -200000;
    y[0] = -200000;
    for (int i = 0; i < n; i++) {
        cin >> x[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        y[i] = r;
        for (int j = 0; j < i; j++) {
            if (x[j] + r < x[i] - r) {
                continue;
            }
            double y1 = y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j]));
            y[i] = max(y[i], y1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%.20lf", y[i+1]);
    }
    cout << endl;
}