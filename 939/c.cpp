#include <iostream>
using namespace std;
long long a[200015];
long long pre[200015];
long long n;
long long s, f;
int t(int h) {
    return ((s - h) % n + n) % n + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    a[0] = a[n];
    cin >> s >> f;
    // sliding windows
    long long p = 0;
    long long ans = 0;
    int h = 1;
    p = 0;
    for (int i = 0; i < f - s; i++) {
        // cout << i << '\n';
        pre[1] += a[i + 1];
        // cout << a[i + 1] << '\n';
        
    }
    // cout << "pre " << pre[1] << '\n';
    ans = pre[1];
    h = 1;
    for (int i = 2; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i + f - s - 1] - a[i - 1];
        if (pre[i] > ans or pre[i] == ans and t(i) <= t(h)) {
            ans = pre[i];
            h = i;
        }
        // cout << "pre " << pre[i] << '\n';
    }
    cout << t(h) << '\n';
}