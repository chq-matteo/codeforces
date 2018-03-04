#include <iostream>
#include <vector>
using namespace std;
vector<int> f['z' + 1];
int fq['z' + 1];
int main() {
    string s;
    double d = 0;
    cin >> s;
    int p, mp;
    for (int i = 0; i < s.size(); i++) {
        f[s[i] - 'a'].push_back(i);
        // cout << s[i] << ' ' << f[s[i] - 'a'].size() << endl;
    }
    for (int k = 0; k < 'z' - 'a' + 1; k++) {
        mp = 0;
        for (int i = 0; i < s.size(); i++) {
            p = 0;
            for (int j = 0; j < f[k].size(); j++) {
                fq[s[(i + f[k][j]) % s.size()] - 'a']++;
            }
            for (int j = 0; j < 'z' - 'a' + 1; j++) {
                if (fq[j] == 1) {
                    p += 1;
                }
                fq[j] = 0;
            }
            // cout << (char)( i+'a' ) << ' ' <<  mp << ' ' << p << endl;
            mp = max(mp, p);
        }
        d += mp;
    }
    cout << d / (double)s.size() << '\n';
}