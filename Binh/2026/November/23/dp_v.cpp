// https://atcoder.jp/contests/dp/tasks/dp_v

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, inf = 2e18;

struct SOLVE{
    int n, m, ans = 0, mod;

    vector<vector<int>> adj;
    vector<int> a;
    vector<int> dp;
    void dfs(int x = 1, int p = 0){
        dp[x] = 1;
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            dp[x] = (dp[x] * (dp[i] + 1)) % mod; 
        }
    }

    void reroot(int x = 1, int p = 0, int fp = 0){
        vector<int> pre = {(fp + 1) % mod}, suf = {1 % mod};
        for (int i : adj[x]) if (i != p){
            pre.emplace_back(pre.back() * (dp[i] + 1) % mod);
        }
        for (int i = (int)adj[x].size() - 1; i >= 0; i--){
            int j = adj[x][i];
            if (j == p) continue;
            suf.emplace_back(suf.back() * (dp[j] + 1) % mod);
        }
        reverse(suf.begin(), suf.end());
        a[x] = pre.back();
        int c = 0;
        for (int i : adj[x]) if (i != p){
            int cur = pre[c] * suf[c + 1] % mod;
            reroot(i, x, cur);
            c++;
        }
    }

    void solve(){
        cin >> n >> mod;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs();
        reroot();
        for (int i = 1; i <= n; i++)
            cout << a[i] << "\n";
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
