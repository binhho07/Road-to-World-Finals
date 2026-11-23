// https://codeforces.com/problemset/problem/1088/E

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 2>

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, mx = -1e18, k = 0, ans = maxn, cc = 0;

    vector<vector<int>> adj, cadj;
    vector<int> a, vis;
    vector<array<array<int, 2>, 2>> dp;


    int dfs(int x, int p, bool cut){
        int best = a[x];
        for (int i : adj[x]) if (i != p)
            best += max(0ll, dfs(i, x, cut));
        if (!cut) mx = max(mx, best);
        else if (best == mx){
            k++;
            return 0;
        }
        return best;
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2, u, v, w; i <= n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs(1, 0, false);             
        dfs(1, 0, true);
        cout << mx * k << " " << k;
    }       
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
    #endif    
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
