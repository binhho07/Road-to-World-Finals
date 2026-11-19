// https://atcoder.jp/contests/abc147/tasks/abc147_d

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int p[maxn], sq[maxn];

struct SOLVE{
    int n, q;
    void solve(){
        cin >> n;
        vector<int> cnt(60);
        int ans = 0;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
            for (int j = 0; j < 60; j++){
                if (x >> j & 1)
                    cnt[j]++;
            }
        }

        for (int x : a){
            for (int j = 0; j < 60; j++){
                if (x >> j & 1){
                    ans = (ans + (1ll << j) % mod * (n - cnt[j])) % mod;
                }
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
