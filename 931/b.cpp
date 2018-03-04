#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> v;
vector<int> w;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    tie(a, b) = tuple<int,int>{min(a,b), max(a,b)};
    for (int i = 0; i < n; i++) {
        v.push_back(i+1);
    }
    int rnd = 1;
    int ans = 0;
    while (v.size() > 1) {
        // cout << v.size() << endl;
        for (int i = 0; i < v.size(); i+=2) {
            if (v[i] == a && v[i+1] == b) {
                ans = rnd;
            }
            w.push_back(v[i] == a || v[i] == b ? v[i] : v[i+1]);
        }
        rnd ++;
        v = w;
        w = {};
    }
    if (ans == rnd - 1) {
        cout << "Final!\n";
    }
    else {
        cout << ans << endl;
    }
}