// https://codeforces.com/problemset/problem/1083/A

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 3>

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, ans = 0, root;

    vector<vector<pair<int, int>>> adj;
    vector<int> a;
    vector<int> dp;
    vector<pair<int, int>> f;

    ii merge(ii x, int y){
        vector<int> v = {x[0], x[1], x[2], y};
        sort(v.rbegin(), v.rend());
        x = {v[0], v[1], v[2]};
        return x;
    }

    void dfs(int x = 1, int p = 0){
        dp[x] = 0;
        for (auto [i, j] : adj[x]) if (i != p){
            dfs(i, x);
            dp[x] = max(dp[x], dp[i] - j);
        }
        dp[x] += a[x];
    }

    void reroot(int x = 1, int p = 0, int fp = 0){
        fp = max(fp, 0ll);
        vector<int> pre = {fp}, suf = {0};
        for (auto [i, j] : adj[x]) if (i != p){
            pre.emplace_back(max(pre.back(), dp[i] - j));
        }

        for (int i = (int)adj[x].size() - 1; i >= 0; i--){
            auto [v, j] = adj[x][i];
            if (v == p) continue;
            suf.emplace_back(max(suf.back(), dp[v] - j));
        }

        reverse(suf.begin(), suf.end());
        
        ans = max(ans, a[x] + pre.back());

        int c = 0;
        for (auto [i, j] : adj[x]) if (i != p){
            int mx = max(pre[c], suf[c + 1]);
            mx += a[x] - j;
            reroot(i, x, mx);
            c++;
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        f.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 2, u, v, w; i <= n; i++)
            cin >> u >> v >> w,
            adj[u].emplace_back(v, w),
            adj[v].emplace_back(u, w);
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
