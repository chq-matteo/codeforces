#include <iostream>
#include <vector>
using namespace std;
vector<int> e[1010];
int main() {
    int n, p;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> p;
        e[p].push_back(i + 1);
    }
    bool spruce = true;
    for (int i = 1; i <= n; i++) {
        int leaves = 0;
        for (auto n : e[i]) {
            if (e[n].size() == 0) {
                leaves++;
            }
        }
        if (leaves < 3 and e[i].size() != 0) {
            spruce = false;
        }
    }
    if (spruce) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}