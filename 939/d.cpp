#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
int p[100];
struct k {
    char a, b;
};
int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            v[a[i] - 'a'].push_back(b[i] - 'a');
            v[b[i] - 'a'].push_back(a[i] - 'a');
        }
    }
    for (int i = 0; i < 26; i++) {
        p[i] = 0;
    }
    vector<int> q;
    vector<k> l;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (!p[i]) {
            q.push_back(i);
            p[i] = i + 1;
            while (!q.empty()) {
                int top = q.back();
                q.pop_back();
                for (auto e : v[top]) {
                    if (!p[e]) {
                        p[e] = i + 1;
                        ans += 1;
                        q.push_back(e);
                        l.push_back({i + 'a', e + 'a'});
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < ans; i++) {
        cout << l[i].a << ' ' << l[i].b << '\n';
    }
}