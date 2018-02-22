#include <iostream>
using namespace std;
int f[5005];
bool t(int i) {
    return i == f[f[f[i]]];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i] --;
    }

    bool ans = false;
    for (int i = 0; i < n; i++) {
        ans |= t(i);
    }
    
    if (ans) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}