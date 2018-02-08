#include <iostream>
using namespace std;
int solve(int x, int y) {
    if (y == 1) return x == 0;
    return y >= 1 && x >= y - 1 && (x % 2) == (y - 1) % 2;
}
int main() {
    int x, y;
    cin >> x >> y;
    bool cansolve = solve(x, y);
    if (cansolve) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}