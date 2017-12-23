#include <iostream>
#include <set>
using namespace std;
int main() {
    // case 1 a in w then a is not the shocker letter
    // case 2 a not in w then a is not the shocker letter
    // case 3 when it is not hte last action s is not s shocker letter
    ios::sync_with_stdio(false);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    set<char> guess(alphabet.begin(), alphabet.end());

    int n;
    char c;
    string w;
    set<char> unique;
    cin >> n;
    bool found = false;
    int could = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> c >> w;
        switch(c) {
            case '.':
                for (auto a : w) {
                    auto g = guess.find(a);
                    if (g != guess.end()) {
                        guess.erase(g);
                    }
                }
                break;
            case '!':
                if (found) could++;
                unique.clear();
                unique.insert(w.begin(), w.end());
                for (auto a : alphabet) {
                    auto g = unique.find(a);
                    if (g == unique.end()) {
                        auto q = guess.find(a);
                        if (q != guess.end()) {
                            guess.erase(q);
                        }
                    }
                }
                break;
            case '?':
                if (found) could++;            
                for (auto a : w) {
                    auto g = guess.find(a);
                    if (g != guess.end()) {
                        guess.erase(g);
                    }
                }
                break;
        }
        if (guess.size() <= 1) {
            found = true;
        }
    }  
    cout << could << endl;
}