#include <iostream>
using namespace std;
uint64_t log2(uint64_t n) {
    uint64_t ans = 0;
    while (n) {
        n = n / 2;
        ans++;
    }
    return ans;
}
int main() {
    uint64_t n, k;
    cin >> n >> k;
    // cout << n << ' ' << k << '\n';
    if (k == 1) {
        cout << n << '\n';
    }
    else {
        uint64_t ans = 1;
        cout << ((ans << log2(n)) - (uint64_t)1) << '\n';
    }
}