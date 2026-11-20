// https://atcoder.jp/contests/abc471/tasks/abc471_e

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 998244353;

int inv[maxn], fact[maxn];
 
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
    if (n < k) return 0;
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
        int c1 = C(n - 1, k - 1), c2 = C(n - 2, k - 2);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans = (ans + a[i] * a[i] % mod * c1) % mod;
            sum = (sum + a[i]) % mod;
        }
        for (int i = 1; i <= n; i++){
            int rem = (sum - a[i] + mod) % mod;
            ans = (ans + a[i] * rem % mod * c2) % mod;
        }
        cout << ans;
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
