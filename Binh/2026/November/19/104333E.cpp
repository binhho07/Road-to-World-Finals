// https://codeforces.com/gym/104333/problem/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 2e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q;
    string s;

    int mul(int x, int y){
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
        int sum = 0, prod = 1;
        for (int i = 1, x; i <= n; i++) 
            cin >> x, 
            sum += x,
            prod = prod * i % mod;
        sum %= mod;
        int sp = 0;
        for (int i = 1; i <= n; i++)
            sp = (sp + prod * mul(i, mod - 2)) % mod;
        cout << sp * sum % mod * mul(prod, mod - 2) % mod;
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
