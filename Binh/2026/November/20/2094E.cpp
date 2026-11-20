// https://codeforces.com/contest/2094/problem/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        vector<int> a(n + 1);
        vector<array<int, 2>> cnt(30);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            for (int j = 0; j < 30; j++)
                cnt[j][a[i] >> j & 1]++;
        }
        for (int i = 1; i <= n; i++){
            int cur = 0;
            for (int j = 0; j < 30; j++)
                cur += (1ll << j) * cnt[j][(a[i] >> j & 1) ^ 1];
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
