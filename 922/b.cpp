#include <iostream>
using namespace std;
int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int c = n; c >= 1; c--) {
        for (int b = c; b >= 1; b--) {
            int a = c ^ b;
            if (a <= b and a + b > c and a + c > b and a >= 1) {
                ans += 1;
                // cout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
    cout << ans;
}