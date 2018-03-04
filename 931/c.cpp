#include <iostream>
using namespace std;
int a[3];
int x[100005];
int main() {
    int n;
    int m = 100000, M = -100000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        m = min(m, x[i]);
        M = max(M, x[i]);
    }
    for (int i = 0; i < n; i++) {
        a[x[i] - m]++;
    }
    if (min(a[0], a[2]) > a[1] / 2) {
        int f = min(a[0], a[2]);
        cout << n - 2 * f << '\n';
        bool fst = true;
        for (int i = 0; i < a[2] - f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m+2;
        }
        for (int i = 0; i < a[1] + 2*f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m+1;
        }

        for (int i = 0; i < a[0] - f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m;
        }
    }
    else if (a[2] != 0) {
        int f = a[1] / 2;
        cout << n - 2 * f << '\n';
        bool fst = true;
        for (int i = 0; i < a[2] + f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m+2;
        }
        for (int i = 0; i < a[1] - 2*f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m+1;
        }

        for (int i = 0; i < a[0] + f; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << m;
        }
    }
    else {
        cout << n << '\n';
        bool fst = true;
        for (int i = 0; i < n; i++) {
            if (!fst) {
                cout << ' ';
            }
            if (fst) {
                fst = false;
            }
            cout << x[i];
        }
    }
    cout << '\n';
    
}