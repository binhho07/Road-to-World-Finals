// https://codeforces.com/problemset/problem/461/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, ans = 0;

    vector<vector<int>> adj;
    vector<int> a;
    vector<array<int, 2>> dp;

    array<int, 2> merge(array<int, 2> x, const array<int, 2>& y){
        x[0] += y[0];
        x[1] += y[1];
        return x;
    }

    void dfs(int x = 1, int p = 1){
        dp[x][a[x]] = 1;
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            dp[x][1] = (dp[x][1] * dp[i][0] + dp[x][0] * dp[i][1] + dp[x][1] * dp[i][1]) % mod;
            dp[x][0] = (dp[x][0] * dp[i][0] + dp[x][0] * dp[i][1]) % mod;
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 2, u, v; i <= n; i++)
            cin >> u,
            v = i,
            adj[++u].emplace_back(v),
            adj[v].emplace_back(u);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        dfs();
        cout << dp[1][1];
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
