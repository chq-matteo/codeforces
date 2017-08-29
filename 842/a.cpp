#include <iostream>
using namespace std;
int main() {
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    // k*b = a;
    for(int i = x; i <= y; i++) {
        if(k*i >= l && k*i <= r) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}