#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int L0 = 0, L1 = 0;
    int O0 = 0, O1 = 0;
    for (char c : s) {
        if (c == 'O') ++O1;
        else ++L1;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'O') {
            --O1;
            ++O0;
        }
        else {
            --L1;
            ++L0;
        }
        if (L0 != L1 && O0 != O1) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
