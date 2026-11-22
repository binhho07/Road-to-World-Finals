// https://codeforces.com/gym/106666/problem/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; (1 << j) <= i; j++){
                dp[i] += dp[i - (1 << j)];
                if (dp[i] >= mod) dp[i] -= mod;
            }
        cout << dp[n] * 2 % mod;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
