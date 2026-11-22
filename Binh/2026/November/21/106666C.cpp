// https://codeforces.com/gym/106666/problem/C

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5;

struct SOLVE{
    int n, m, t, c, ans = 0;

    void solve(){
        cin >> n >> m;
        n++;
        vector<int> v = {1};
        for (int i = 0; i <= 62; i++){
            v.emplace_back(1ll << i);
        }
        int cnt = 0;
        for (int i : v){
            if (m == 0) break;
            int take = min(m, i);
            ans += (n - cnt) * take;
            m -= take;
            cnt++;
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
