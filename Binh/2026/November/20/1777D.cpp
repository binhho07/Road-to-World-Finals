// https://codeforces.com/contest/1777/problem/D

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;
    vector<vector<int>> adj;
    vector<int> mu;

    int dfs(int x, int p){
        int mx = 1;
        for (int i : adj[x]) if (i != p){
            mx = max(mx, dfs(i, x) + 1);
        }
        ans = (ans + mx * mu[n - 1]) % mod;
        return mx;
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        mu.resize(n + 1);
        mu[0] = 1;
        for (int i = 1; i <= n; i++)
            mu[i] = mu[i - 1] * 2ll % mod;
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs(1, 1);
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
