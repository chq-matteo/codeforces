#include <iostream>
#include <vector>
#include <set>
using namespace std;
int p[100005];
int d[100005];
vector<int> e[100005];
set<int> uniq;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i] --;
        e[p[i]].push_back(i);
    }
    vector<int> q;
    q.push_back(0);
    while (!q.empty()) {
        int t = q.back();
        q.pop_back();
        for (auto v : e[t]) {
            if (d[v] == 0 && v != 0) {
                d[v] = d[t] + 1;

                q.push_back(v);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        auto g = uniq.find(d[i]);
        if (g == uniq.end()) {
            uniq.insert(d[i]);
        }
        else {
            uniq.erase(g);
        }
    }
    cout << uniq.size() << '\n';
}