#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e9 + 5;

void solve() {
    int t;
    cin >> t;
    int n;
    cin >> n;
    int a, b, c;
    if (n == 1) {
        cin >> a;
        if (t % a == 0) {
            cout << 1 << '\n';
            return;
        }
        cout << 0 << '\n';
        return;
    }
    if (n == 2) {
        cin >> a >> b;
        int ans = 0;
        for (int remA = 0; remA < b; ++remA) {
            if ((t - a * remA) % b != 0) continue;
            for (int remB = 0; remB < a; ++remB) {
                if (((t - a * remA) / b - remB) % a != 0) continue;
                int N = ((t - a * remA) / b - remB) / a;
                ans += N + 1;
            }
        }
        cout << ans << '\n';
        return;
    }
    cin >> a >> b >> c;
    int ans = 0;
    for (int remA = 0; remA < c; ++remA) {
        for (int remB = 0; remB < c; ++remB) {
            int need = t - a * remA - b * remB;
            if (need % c != 0) continue;
            if (t - a * remA - b * remB < 0) continue;
            int N = (t - a * remA - b * remB) / c;
            for (int cum = 0; cum < b; ++cum) {
                if (N - a * cum < 0) continue;
                int N1 = (N - a * cum) / b;
                for (int sex = 0; sex < a; ++sex) {
                    if (N1 - sex < 0) continue;
                    int C = (N1 - sex) / a;
                    ans += (C + 1) * (C + 2) / 2;
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
