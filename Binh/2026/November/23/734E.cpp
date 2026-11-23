// https://codeforces.com/problemset/problem/734/E

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 3>

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, ans = maxn, cc = 0;

    vector<vector<int>> adj, cadj;
    vector<int> a, vis, dp;

    void dfs(int x = 1, int p = 0){
        dp[x] = 0;
        for (auto i : cadj[x]) if (i != p){
            dfs(i, x);
            dp[x] = max(dp[x], dp[i] + 1);
        }
    }

    void reroot(int x = 1, int p = 0, int fp = 0){
        vector<int> pre = {fp}, suf = {0};
        for (auto i : cadj[x]) if (i != p){
            pre.emplace_back(max(pre.back(), dp[i] + 1));
        }

        for (int i = (int)cadj[x].size() - 1; i >= 0; i--){
            auto v = cadj[x][i];
            if (v == p) continue;
            suf.emplace_back(max(suf.back(), dp[v] + 1));
        }

        reverse(suf.begin(), suf.end());
        
        ans = min(ans, pre.back());

        int c = 0;
        for (auto i : cadj[x]) if (i != p){
            int mx = max(pre[c], suf[c + 1]);
            reroot(i, x, mx + 1);
            c++;
        }
    }

    void compress(int x, int p){
        vis[x] = cc;
        for (int i : adj[x]) if (!vis[i] && a[i] == a[x]){
            compress(i, x);
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        cadj.resize(n + 1);
        vis.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2, u, v, w; i <= n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            cc++;
            compress(i, i);
        }
        for (int i = 1; i <= n; i++)
            for (int j : adj[i])
                if (vis[i] != vis[j])
                    cadj[vis[i]].emplace_back(vis[j]);

        dfs();
        reroot();
        cout << ans;
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
