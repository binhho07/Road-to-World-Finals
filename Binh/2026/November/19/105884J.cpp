// https://codeforces.com/gym/105884/problem/J

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
    int n, k;
    void solve(){
        cin >> n >> k;
        vector<vector<int>> f(n + 1);
        vector<int> a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; i++){
            int32_t x; cin >> x;
            for (int32_t j = 2; j * j <= x; j += (j == 2 ? 1 : 2)){
                if (x % j == 0){
                    cnt[j]++;
                    f[i].emplace_back(j);
                    while (x % j == 0)
                        x /= j;
                }
            }
            if (x > 1)
                cnt[x]++,
                f[i].emplace_back(x);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j : f[i]){
                int tot = n - cnt[j];
                cnt[j]--;
                ans = (ans + j * C(tot, k - 1)) % mod;
            }
        }
        cout << ans << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    init();
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
