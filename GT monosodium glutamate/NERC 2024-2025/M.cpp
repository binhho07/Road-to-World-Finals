#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5;

struct SOLVE{
    int n, m, t, c;
    vector<pair<int, int>> ans;
    vector<int> match, p, vis;
    vector<vector<int>> adj;
    void go(int s){
        int cur = s;
        vector<int> order;
        while (true){
            order.emplace_back(cur);
            vis[cur] = 1;
            int pc = p[cur];
            if (vis[pc]) break;
            order.emplace_back(pc);
            vis[pc] = 1;
            if (!match[pc] || vis[match[pc]]) break;
            cur = match[pc];
        }
        for (int i = 1; i < (int)order.size() - i; i++)
            ans.emplace_back(order[i], order[(int)order.size() - i]);
    }

    void dfs(int x = 1, int p = 1){
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
        }
        if (!match[p] && !match[x])
            match[p] = x,
            match[x] = p;
    }

    void solve(){
        cin >> n;
        int N = 2 * n;
        vis.resize(N + 1);
        p.resize(N + 1);
        match.resize(N + 1);
        adj.resize(N + 1);
        map<int,int> mp;
        for (int i = 1; i <= 2 * n; i++){
            int x; cin >> x;
            if (mp.count(x))
                p[mp[x]] = i,
                p[i] = mp[x];
            else mp[x] = i;
        }
        for (int i = 1; i < 2 * n; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs();
        for (int i = 1; i <= 2 * n; i++)
            if (!match[i] && !vis[i]) {
                go(i);
            }
        for (int i = 1; i <= 2 * n; i++)
            if (!vis[i]) go(i);
        cout << ans.size() << "\n";
        for (auto [i, j] : ans) cout << i << " " << j << "\n";
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
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
