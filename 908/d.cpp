// This code doesn't work yet, but the idea I had was to peel the string with consecutive substrings of aaaa...b
// Things to fix:
// Closed form for the Expected value of numbers of ab-s
// How to combine the subproblems
#include <iostream>
using namespace std;

long long k, pa, pb;
long long mod = 1000000000 + 7;
struct frac {
    long long p;
    long long q;
    friend frac operator+(frac a, frac b) {
        return {
            (a.p * b.q) % mod
            + (a.q * b.p) % mod,
            (a.q * b.q) % mod
        };
    }
    friend frac operator*(frac a, frac b) {
        return {
            (a.p * b.p) % mod,
            (a.q * b.q) % mod
        };
    }
    friend frac operator-(frac a, frac b) {
        return a + {-b.p, b.q};
    }
};
// fraction power
frac fpow(frac a, int b) {
    frac ans = {1, 1};
    frac p = {a.p, a.q};
    int e = 1;
    while(e <= b) {
        if (e & b) {
            // cout << p.p << '/' << p.q << endl;
            ans = ans * p;
        }
        p = p * p;
        e = e << 1;
    }
    // cout << a.p << '/' << a.q << '^' << b << " = " << ans.p << '/' << ans.q << endl;
    return ans;
}


frac calc(int a, int ab) {
    cout << a << ' ' << ab << endl;
    if (ab <= k - 1) {
        frac ans = (frac{pb, pa + pb} * frac{pa, pb} * frac{pa + pb, pb}) - (frac{pa, pa + pb} * frac{1, 1} - (frac{k - 1, 1} * fpow()));
        for (int i = 0; a + a + i < k; i++) {
            if (i == 0 and a == 0) continue;
            cout << a << ' ' << ab << ' ' << i << endl;
            
            ans = ans + ((calc(a + i, ab + a + i) + frac{a + i, 1}) * fpow({pa, pa + pb}, i) * frac{pb, pa + pb});
        }
        return ans;
    }
    else {
        return {0, 1};
    }
}
long long egcd(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = egcd(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
int main() {
    cin >> k >> pa >> pb;
    frac ans = calc(0, 0) * frac{pb + pa, pb};
    long long q1 = 0;
    long long y = 0;
    long long g = egcd(ans.q, mod, &q1, &y);
    cout << ans.p / g << ' ' << ans.q / g<< endl;
    
    cout << (((ans.p * q1) % mod + mod) % mod) << endl;
}