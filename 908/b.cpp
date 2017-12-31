// Just simulate every 4! possibility
#include <iostream>
#include <algorithm>
using namespace std;
char t[100][100];
char p[200];
int dir[4][2] = {
    {1, 0}, // down
    {0, 1}, // right
    {-1, 0}, // up
    {0, -1}, // left
};
int n, m;
int sx, sy;
bool go(int * mapping) {
    char * q = p;
    int x = sx;
    int y = sy;
    while(*q) {
        x += dir[mapping[(*q) - '0']][0];
        y += dir[mapping[(*q) - '0']][1];
        if (x < 0 || x >= n || y < 0 || y >= m || t[x][y] == '#') {
            return false;
        }
        if (t[x][y] == 'E') return true;
        q += 1;
    }
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        char * q = t[i];
        for (int j = 0; j < m; j++) {
            if (t[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    cin >> p;
    int mapping[] = {0, 1, 2, 3};
    int can = 0;
    do {
        if(go(mapping))
            can ++;
    } while(next_permutation(mapping, mapping+4));
    cout << can << endl;
}