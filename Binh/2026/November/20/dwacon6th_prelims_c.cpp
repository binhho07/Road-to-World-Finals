// https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_c

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int inv[maxn], fact[maxn];
int dp[25][1005];
 
inline int mu(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
 
inline int C(int n, int k)
{
    if (k > n) return 0;
    if (k < 0) return 0;
    return fact[n] * inv[k] % mod * inv[n - k] % mod;
}
 
void init()
{
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
    inv[maxn - 1] = mu(fact[maxn - 1], mod - 2);
    for (int i = maxn - 1; i > 2; i--) inv[i - 1] = inv[i] * i % mod;
}

struct SOLVE{
    int n, k, q, ans = 0;

    void solve(){
        cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= k; i++) cin >> a[i];
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= n; j++)
                for (int r = 0; r <= min(j, a[i]); r++) {
                    dp[i][j] = (dp[i][j] 
                                + dp[i - 1][j - r] * C(n - j + r, r) % mod * C(n - r, a[i] - r)) % mod;
                }
        cout << dp[k][n];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    init();
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
