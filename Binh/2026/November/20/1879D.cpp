// https://codeforces.com/contest/1879/problem/D

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 998244353;
int a[maxn];
array<int, 30> p;
array<array<int, 2>, 30> pre, cnt;

struct SOLVE{
    int n, m, q, ans = 0;
    void solve(){
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i < 30; i++)
            cnt[i][0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < 30; j++){
                if (a[i] >> j & 1){
                    p[j] ^= 1;
                }
                ans = (ans 
                        + cnt[j][p[j] ^ 1] * (1ll << j) % mod * i % mod 
                        - pre[j][p[j] ^ 1] + mod) % mod;
                cnt[j][p[j]]++;
                (pre[j][p[j]] += (1ll << j) * i) %= mod;
            }
        }
        cout << ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
