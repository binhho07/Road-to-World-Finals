#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 998244353, N = 2e5 + 10;

int dp[N][3][3][3];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][2][2][2] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                for (int l = 0; l <= 2; ++l) {
                    dp[i][j][k][l] = dp[i - 1][j][k][l];
                }
            }
        }

        int x = a[i] % 2;

        dp[i][2][2][x] += dp[i - 1][2][2][2];
        dp[i][2][0][x] += dp[i - 1][2][2][0];
        dp[i][2][1][x] += dp[i - 1][2][2][1];
        dp[i][0][0][x] += dp[i - 1][2][0][0];
        dp[i][0][1][x] += dp[i - 1][2][0][1];
        dp[i][1][0][x] += dp[i - 1][2][1][0];
        dp[i][1][1][x] += dp[i - 1][2][1][1];
        
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                for (int l = 0; l <= 1; ++l) {
                    if ((j + k + l) % 2 == 1) continue;
                    if ((k + l + x) % 2 == 1) continue;
                    dp[i][k][l][x] += dp[i - 1][j][k][l];
                }
            }
        }

        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                for (int l = 0; l <= 2; ++l) {
                    dp[i][j][k][l] %= M;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if ((i + j + k) % 2 == 0) {
                    ans += dp[n][i][j][k];
                }
            }
        }
    }
    cout << ans % M << '\n';

}
