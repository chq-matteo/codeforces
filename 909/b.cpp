// We count the maximum overlapping interval of [0, N]
#include <iostream>
using namespace std;
int v[120];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = i; k < j; k++) {
                v[k] ++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, v[i]);
    }
    cout << ans << '\n';
}