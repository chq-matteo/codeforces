#include <iostream>
using namespace std;
int main() {
    int n, x, y;
    x = 0;
    y = 0;
    string s;
    cin >> n >> s;
    int a = -2;
    int b = 0;
    int ans = 0;
    for (auto c : s) {
        if (c == 'U') {
            x += 0;
            y += 1;
        }
        else {
            x += 1;
            y += 0;
        }
        if (x > y) {
            if (a != 1 and a != -2 and b == 0) ans++;
            a = b;
            b = 1;
        }
        else if (y > x) {
            if (a != -1 and a != -2 and b == 0) ans++;
            a = b;
            b = -1;
        }
        else {
            a = b;
            b = 0;
        }
    }
    cout << ans << '\n';
}