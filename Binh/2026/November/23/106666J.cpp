#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, inf = 2e18;

struct SOLVE{
    int n, m, T;
    vector<vector<pair<int, int>>> adj;

    bool check(int cap){
        vector<int> order = {1};
        vector<int> vis(n + 1, 0), cnt(n + 1, 0);
        vis[1] = 1;
        for (int i = 0; i < order.size(); i++){
            int u = order[i];
            for (auto& [v, w] : adj[u])
                if (!vis[v]) order.emplace_back(v), vis[v] = u;
        }
        vector<vector<int>> dp(n + 1);
        reverse(order.begin(), order.end());
        for (int u : order){
            cnt[u] = 1;
            for (auto& [v, w] : adj[u]) if (v != vis[u]){
                cnt[u] += cnt[v];
            }
            dp[u].resize(cnt[u] + 1, inf);
            dp[u][1] = 0;
            int cur = 1;
            for (auto& [v, w] : adj[u]) if (v != vis[u]){
                for (int j = min(cap, cur); j >= 1; j--){
                    int mn = inf;
                    for (int k = 1; k <= cnt[v]; k++){
                        if (j + k <= cap) dp[u][j + k] = min(dp[u][j + k], dp[u][j] + dp[v][k]);
                        if (j <= cap) mn = min(mn, dp[v][k] + w);
                    }
                    dp[u][j] += mn;
                }
                cur += cnt[v];
            }       
        }
        int mn = inf;
        for (int i = 1; i <= min(cap, cnt[1]); i++)
            mn = min(mn, dp[1][i]);
        return mn <= T;
    }

    void solve(){
        cin >> n >> T;
        adj.resize(n + 1);
        for (int i = 1, u, v, w; i < n; i++)
            cin >> u >> v >> w,
            adj[u].emplace_back(v, w),
            adj[v].emplace_back(u, w);

        int l = 1, r = n, ans;
        while (l <= r){
            int mid = (l + r) / 2;
            if (check(mid))
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
    #endif    
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
