// https://codeforces.com/contest/2260/problem/F

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 4>

using namespace std;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, m, found = 0;
    vector<int> p, par, h, mark;
    vector<vector<pair<int, int>>> adj;
    vector<tuple<int, int, int>> edges, all;

    int fp(int u){
        return p[u] < 0 ? u : p[u] = fp(p[u]);
    }

    int unite(int u, int v){
        if ((u = fp(u)) == (v = fp(v))) return 1;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
        return 0;
    }

    void dfs(int x = 1, int p = 0){
        h[x] = h[p] + 1;
        for (auto [i, j] : adj[x]) if (i != p)
            par[i] = j, dfs(i, x);
    }

    bool check(int u, int v, int id){
        for (int i = 1; i <= m; i++) mark[i] = 0;
        mark[id] = 1;
        while (u != v){
            if (h[u] > h[v]) swap(u, v);
            auto [x, y, z] = all[par[v] - 1];
            v = x + y - v;
            mark[z] = 1;
        }
        for (int i = 1; i <= n; i++)
            p[i] = -1;
        for (auto [u, v, id] : all)
            if (mark[id] == 0)
                unite(u, v);
        return p[fp(1)] == -n;
    }
 
    void solve(){
        cin >> n >> m;
        p.resize(n + 1, -1);
        par.resize(n + 1);
        adj.resize(n + 1);
        h.resize(n + 1);
        mark.resize(m + 1);
        for (int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            all.emplace_back(u, v, i);
        }
        int times = n * 2;
        while (times--){
            edges.clear();
            for (int i = 1; i <= n; i++)
                adj[i].clear(), 
            p[i] = -1;
            for (int i = 1; i <= m; i++){
                auto& [u, v, id] = all[i - 1];
                id = i;
                if (unite(u, v)){
                    edges.emplace_back(u, v, i);
                } else{
                    adj[u].emplace_back(v, i);
                    adj[v].emplace_back(u, i);
                }
            }
            dfs();
            for (auto [u, v, id] : edges){
                if (check(u, v, id)) return cout << "YES\n", void();
            }
            random_shuffle(all.begin(), all.end());
        }
       cout << "NO\n";
    }       
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
    #endif    
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
