#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    long long a;
    long long m = n + 1;
    long long ans = 0;
    long long h = 0;
    for (int i = 0; i < k; i++) {
        cin >> a;
        if (n % a < m) {
            m = n % a;
            ans = 1 + i;
            h = n / a;
        }
    }
    cout << ans << ' ' << h << '\n';
}