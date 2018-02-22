#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    int a;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = max(ans, min(abs(1 - a), abs(1000000 - a)));
    }
    cout << ans << '\n';
}