// https://toph.co/p/easy-peasy-subset-sum

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int mod = 1e9 + 7;

struct SOLVE{
    int n, m;
    void solve(){
        cin >> n;
        vector<int> a(n);
        int mul = 1;
        for (int i = 1; i <= n - 2; i++)
            mul = (mul * 2ll) % mod;
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());
        int ans = 0, pre = 0;
        for (int i = 0; i < n; i++){
            ans = (ans + (a[i] * i % mod - pre + mod) % mod * mul) % mod;
            pre = (pre + a[i]) % mod;
        }
        cout << ans;
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
