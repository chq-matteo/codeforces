#include <iostream>
using namespace std;
int main() {
    long long r, d, n, x, y, s;
    cin >> r >> d >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> s;
        int di = x*x + y*y;
        if(r - s >= 0 && di <= (r-s)*(r-s) && di >= (r-d+s)*(r-d+s)) {
            ans ++;
        }
    }
    cout << ans << '\n';
}