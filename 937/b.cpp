#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long p, y;
    cin >> p >> y;
    long long p2 = p * p;
    long long ans = -1;
    for (int i = y; i > p; i--) {
        bool ok = true;
        for (int j = 2; j <= min((int) sqrt(i) + 2, (int)p); j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}