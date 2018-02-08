#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct p {
    long long s, h, sh;
};
bool comp(p a, p b) {
    return a.s * b.h > a.h * b.s;
}
vector<p> t;
int main() {
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    string s;
    for (long long i = 0; i < n; i++) {
        cin >> s;
        long long ps = 0, ph = 0, psh = 0;
        for (auto c : s) {
            switch (c) {
                case 's':
                    ps +=1;
                    break;
                case 'h':
                    ph += 1;
                    psh += ps;
                    break;
            }
        }
        t.push_back({ps, ph, psh});
    }
    sort(t.begin(), t.end(), comp);
    long long ps = 0, ph = 0, psh = 0;
    for (auto q : t) {
        psh += q.sh;
        psh += q.h * ps;
        ps += q.s;
        ph += q.h;
    }    
    cout << psh << endl;
}