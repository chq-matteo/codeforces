// I actually didn't solve this problem during the contest because I didn't enforce positive remainders
// We can solve the problem with dynamic programming
// states[m][o] is how many different ways you can indent the statements from o onwards knowing that you can give the first statement indentation level from 0 to m
// sum[m][o] holds sum(states[i][o] for 0 <= i <= m)
// lvs[o] has the difference in indentation level of the o-th statement (0 for simple statement, 1 for a single loop, 2 for 2 nested loops)
// We can prove that states[m][o] = sum(states[i][o] for lvs[o] <= i <= m + lvs[o])
// So we can memoize the cumulative sums to compute the summation in constant time
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> lvs;
int n;
char c;
int mod = 1000000000 + 7;
int states[5050][5050];
int sum[5050][5050];
int get_sum(int a, int b, int o) {
    if (a > 0) {
        return ((sum[b][o] - sum[a - 1][o]) % mod + mod) % mod;
    }
    else
        return sum[b][o];
}
int how_many(int m, int o) {
    if (states[m][o] != -1) return states[m][o];
    int ans = 0;
    ans = get_sum(lvs[o], m + lvs[o], o + 1);
    states[m][o] = ans;
    return ans;
}
int main() {
    cin >> n;
    int lv = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 's') {
            lvs.push_back(lv);
            lv = 0;
        }
        else {
            lv++;
        }
    }
    memset(states, -1, sizeof(states));
    int m = n;
    n = lvs.size();
    // initialize the base cases
    for (int i = 0; i < 5050; i++) {
        states[i][n - 1] = i + 1;
        if (i > 0)
            sum[i][n - 1] = (((sum[i - 1][n - 1] + states[i][n-1]) % mod) + mod) % mod;
        else
            sum[i][n-1] = states[i][n-1];
    }

    int h = 0;
    for (int j = n - 2; j >= 0; j--) {
        // cout << lvs[j] << endl;
        for (int i = 0; i < 5010 - lvs[j]; i++) {
            h = how_many(i, j);
            // cout << states[i][j] << ' ';
            if (i > 0)
                sum[i][j] = ((sum[i - 1][j] + h) % mod + mod) % mod;
            else
                sum[i][j] = states[i][j];
        }
        // cout << '\n';
    }
    cout << how_many(0, 0) << '\n';    
}