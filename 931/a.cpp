#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int m = abs(a - b) / 2;
    int n = abs(a - b) - m;
    cout << m * (m+1) / 2 + n * (n + 1) / 2 << endl;
}