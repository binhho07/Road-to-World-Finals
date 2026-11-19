// https://codeforces.com/gym/104375/problem/J

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int p[maxn], sq[maxn];

struct SOLVE{
    int n, q;
    
    int mul(int x, int y){
        int ans = 1;
        while (y){
            if (y & 1)
                ans = (ans * x) % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    }

    int get(int l, int r){
        if (r < l) return 0;
        return (p[r] - p[l - 1] + mod) % mod;
    }

    int getsq(int l, int r){
        if (r < l) return 0;
        return (sq[r] - sq[l - 1] + mod) % mod;
    }
    void solve(){
        cin >> n >> q;
        p[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            cin >> p[i];
            sq[i] = (sq[i - 1] + p[i] * p[i]) % mod;
            ans = (ans + p[i - 1] * p[i]) % mod;
            p[i] += p[i - 1];
            if (p[i] >= mod) p[i] -= mod;
        }        
        int div2 = mul(2, mod - 2);
        while (q--){
            int l, r; cin >> l >> r;
            int pf = get(1, l - 1), sf = get(r + 1, n), range = get(l, r);
            int res = ans 
                    - pf * range % mod
                    - sf * range % mod
                    - pf * sf % mod
                    - (pf * pf - getsq(1, l - 1) + mod) % mod * div2 % mod
                    - (sf * sf - getsq(r + 1, n) + mod) % mod * div2 % mod
                    + mod * mod;
            cout << res % mod << "\n";
        }
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
