// https://codeforces.com/gym/106666/problem/I

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, CAP = 2e18;

struct SOLVE{
    int n, m, t, c, ans = 0;
    map<pair<int, int>, int> mp;

    int calc(int p, int t){
        if (p == 0 || t == 0) return 1;                     
        if ((1ll << p) >= n) return CAP;        
        if (mp.count({p, t})) return mp[{p, t}];
        int a = calc(p - 1, t - 1);
        __int128 res = (__int128)((1ll << p) - 1) * a;
        if (res >= n) return mp[{p, t}] = CAP;             
        res += calc(p, t - 1);
        return mp[{p, t}] = (res >= CAP ? CAP : res);
    }
    void solve(){
        cin >> n >> c >> t;
        if (n == 1) return cout << 0, void();
        if (t < c) return cout << -1, void();
        t = t / c;
        int l = 1, r = 60; 
        while (l <= r){
            int mid = (l + r) / 2;
            if (calc(mid, t) >= n)
                ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
        // freopen("test.out", "w", stdout);
    #endif    
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
