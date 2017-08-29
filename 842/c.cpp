#include <iostream>
#include <vector>
using namespace std;
int a[200010];
vector<int> e[200010];
int beauty[200010];
int max_beauty[200010];
int parent[200010];
int mcd(int a, int b) {
    if(b > a) {
        int c = b;
        b = a;
        a = c;
    }
    if(b == 0) return a;
    else return mcd(b, a%b);
}
int main() {
    ios::sync_with_stdio(false);
    int n, x, y;
    cin >> n;
    // start at 1
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        beauty[i] = -1;
        max_beauty[i] = -1;
    }
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> s;
    beauty[1] = a[1];
    max_beauty[1] = a[1];
    parent[1] = 0;
    beauty[0] = 0;
    max_beauty[0] = 0;
    a[0] = 0;
    parent[0] = 0;
    s.push_back(1);
    while(!s.empty()) {
        int top = s.back();
        s.pop_back();
        for(auto& node : e[top]) {
            if(beauty[node] == -1) {
                parent[node] = top;
                s.push_back(node);
                beauty[node] = mcd(a[node], beauty[parent[node]]);
                max_beauty[node] = max(beauty[node], beauty[parent[node]]);
                max_beauty[node] = max(max_beauty[node], mcd(a[node], beauty[parent[parent[node]]]));  
                max_beauty[node] = max(max_beauty[node], mcd(a[node], max_beauty[parent[node]]));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i != 1) cout << ' ';
        cout << max_beauty[i];
    }
    cout << '\n';
}