#include <iostream>
using namespace std;
int main() {
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    int c1, c2, c3;
    c3 = max(v4, v3);
    if (c3 > 2 * v3 or c3 > 2 * v4) {
        cout << -1 << endl;
        return 0;
    }
    c2 = max(c3 + 1, max(2 * v4 + 1, v2));
    if (c2 > 2 * v2) {
        cout << -1 << endl;
        return 0;
    }

    c1 = max(c2 + 1, max(2 * v4 + 1, v1));
    if (c1 > 2 * v1) {
        cout << -1 << endl;
        return 0;
    }
    cout << c1 << '\n' << c2 << '\n' << c3 << endl;
}