// https://codeforces.com/problemset/problem/1743/F

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 998244353;
int seg[4 * maxn], mu[maxn];

struct SOLVE{
    int n, m, q, ans = 0;

    void upd(int lx, int rx, int val, int id = 1, int l = 0, int r = maxn - 5){
        if (lx > r || l > rx) return;
        if (lx <= l && r <= rx) return void(seg[id] = val);
        int mid = (l + r) / 2;
        upd(lx, rx, val, id * 2, l, mid);
        upd(lx, rx, val, id * 2 + 1, mid + 1, r);
    }

    int get(int pos, int id = 1, int l = 0, int r = maxn - 5){
        if (l == r) return seg[id];
        int mid = (l + r) / 2;
        if (pos <= mid) return max(seg[id], get(pos, id * 2, l, mid));
        return max(seg[id], get(pos, id * 2 + 1, mid + 1, r));
    }

    int mul(int x, int y){
        if (y < 0) return 1;
        int ans = 1;
        while (y){
            if (y & 1)
                ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    }

    void solve(){
        cin >> n;
        memset(seg, -1, sizeof seg);
        mu[0] = 1;
        for (int i = 1; i <= n; i++){
            int l, r; cin >> l >> r;
            upd(l, r, i);
        }
        for (int i = 0; i <= maxn - 5; i++){
            int last = get(i);
            if (last == -1) continue;
            int pre = mul(3, last - 2) % mod, suf = mul(2, n - last);
            if (last >= 2) pre = pre * 2 % mod;
            ans = (ans + pre * suf) % mod;
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
