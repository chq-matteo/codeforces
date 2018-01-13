#include <iostream>
using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;

    if (n < 32) {
        cout << (m % (1u << n)) << '\n';
    }
    else {
        cout << m << '\n';
    }
}