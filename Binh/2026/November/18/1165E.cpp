// https://codeforces.com/contest/1165/problem/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int mod = 998244353;

struct SOLVE{
    int n, m;
    void solve(){
        cin >> n;
        vector<int> a(n), b(n), id(n);
        for (int i = 1; i <= n; i++){
            cin >> a[i - 1];
            a[i - 1] = a[i - 1] * (i) * (n - i + 1);
        }
        for (int i = 0; i < n; i++) cin >> b[i];
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int x, int y){
            return a[x] < a[y];
        });
        int ans = 0;
        sort(b.rbegin(), b.rend());
        for (int i = 0; i < n; i++){
            ans += a[id[i]] % mod * b[i] % mod;
            ans %= mod;
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
