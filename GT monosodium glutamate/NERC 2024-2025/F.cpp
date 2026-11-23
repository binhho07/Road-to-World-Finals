#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, CAP = 2e18;

struct SOLVE{
    int n, m, t, c, ans = 0;

    void solve(){
        cin >> n;
        array<vector<char>, 2> a;
        a[0].resize(n + 1);
        a[1].resize(n + 1);
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= n; i++)
                cin >> a[j][i];

        vector<array<int, 4>> dp(n + 1);
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++){
            int must = 0;
            if (a[0][i] == '#') must += 1;
            if (a[1][i] == '#') must += 2;

            for (int j = 0; j < 4; j++){
                if ((j & must) != must) continue;
                // horizontal
                int need1 = (j & 1) & (!(must & 1));
                int need2 = (j >> 1 & 1) & (!(must >> 1 & 1));
                dp[i][j] += dp[i - 1][3 - need1 - need2 * 2];

                // vertical
                if (need1 && need2)
                    dp[i][j] += dp[i - 1][3];
                dp[i][j] = min(dp[i][j], 2ll);
            }
        }
        if (dp[n][3] == 1) cout << "Unique\n";
        else if (dp[n][3] == 0) cout << "None\n";
        else cout << "Multiple\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
        // freopen("test.out", "w", stdout);
    #endif    
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
