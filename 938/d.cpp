#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct e {
    int u;
    long long w;
    friend bool operator<(e a, e b) {
        return a.w > b.w;
    }
};
vector<e> l[200005];
long long ans[200005];
int sl;
int main() {
    ios::sync_with_stdio(false);    
    int n, m;
    int u, v;
    long long w;
    cin >> n >> m;
    priority_queue<e> pq;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }
    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        pq.push({i, ans[i]});
    }
    while (pq.size() != 0) {
        auto top = pq.top();
        pq.pop();
        if (top.w > ans[top.u]) continue;
        for (auto k : l[top.u]) {
            if (ans[k.u] > 2 * k.w + top.w) {
                ans[k.u] = 2 * k.w + top.w;
                pq.push({k.u, ans[k.u]});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}