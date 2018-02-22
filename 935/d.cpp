#include <iostream>

using namespace std;
int EQ = 0;
int MORE = 1;
int LESS = 2;
long long P = 1000000000 + 7;
struct f {
    long long p, q;
    friend f operator*(f a, f b) {
        return {(a.p * b.p) % P, (a.q * b.q) % P};
    }
    friend f operator+(f a, f b) {
        return {(a.p * b.q + b.p * a.q) % P, (a.q * b.q) % P};
    }
};
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
 
f dp[100005][2];
bool init[100005][3];
long long n, m;
int s1[100005];
int s2[100005];
int main() {
    cin >> n >> m;
    //cout << n << m << s1 << s2 << endl;
    dp[n][EQ] = {1, 1};
    dp[n][MORE] = {0, 1};
    for (int i = 0; i < n; i++) {
        cin >> s1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s2[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        //cout << i << endl;
        if (s1[i] == 0 and s2[i] == 0) {
            // 1/m they are eq
            dp[i][EQ] = f{1, m} * dp[i+1][EQ];
            // m-1/2m s1 > s2
            dp[i][MORE] = f{m-1, 2 * m} + f{1, m} * dp[i + 1][MORE];
        }
        else if (s1[i] == 0) {
            // 1/m they are eq
            dp[i][EQ] = f{1, m} * dp[i+1][EQ];
            // m - s2[i] / m s1 > s2
            dp[i][MORE] = f{m - s2[i] + 0, m} + f{1, m} * dp[i + 1][MORE];
        }
        else if (s2[i] == 0) {
            // 1/m they are eq
            dp[i][EQ] = f{1, m} * dp[i+1][EQ];            
            // m - s1[i] / m s2 > s1
            dp[i][MORE] = f{s1[i] - 0 - 1, m} + f{1, m} * dp[i + 1][MORE];
            // s1[i] - 1 / m s1 > s2
        }
        else if (s1[i] > s2[i]) {
            // 0 they eq
            dp[i][EQ] = {0, 1};
            // 1 s1 > s2
            dp[i][MORE] = {1, 1};
            // 0 s1 < s2
        }
        else if (s1[i] < s2[i]) {
            // 0 they eq
            dp[i][EQ] = {0, 1};
            
            dp[i][MORE] = {0, 1};
            // 0 s1 > s2
            // 1
        }
        else {
            dp[i][EQ] = dp[i+1][EQ];
            dp[i][MORE] = dp[i+1][MORE];
            // dp[i + 1][EQ]
            // dp[i + 1][MORE]
            // dp[i + 1][LESS]
        }
    }
    long long x, y;
    long long g = egcd(dp[0][MORE].q, P, &x, &y);
    // cout << dp[0][MORE].p << ' ' << dp[0][MORE].q << '\n';
    cout << (((x * dp[0][MORE].p) % P + P) % P) << '\n';
}