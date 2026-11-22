// https://codeforces.com/gym/106666/problem/F

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        if (n == 2) return void(cout << 1);
        map<int, int> mp;
        int w = 0;
        for (int i = 1, x; i <= n; i++)
            cin >> x, mp[x]++, w = max(w, mp[x]);
        if (n - w >= w) cout << 0 << "\n";
        else cout << w - (n - w) - 1 << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
