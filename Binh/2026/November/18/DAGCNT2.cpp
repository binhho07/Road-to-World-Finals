// https://www.spoj.com/problems/DAGCNT2/

#include<bits/stdc++.h>
#define ii pair<int, int>

using namespace std;
const int maxn = 20000;

struct SOLVE{
    int n, m;
    vector<vector<int>> adj;
    vector<int> vis;
    vector<bitset<maxn>> reach;
    void dfs(int x){
        if (vis[x]) return;
        vis[x] = 1;
        reach[x].set(x);
        for (int i : adj[x]){
            dfs(i);
            reach[x] |= reach[i];
        }
    }

    void solve(){
        cin >> n >> m;
        adj = vector<vector<int>>(n);
        vis = vector<int>(n, 0);
        vector<long long> a(n + 8, 0);
        reach = vector<bitset<maxn>>(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].emplace_back(v);    
        }
        for (int i = 0; i < n; i++)
            dfs(i);                     

        int blocks = (n + 7) / 8;
        vector<array<long long, 256>> tbl(blocks);
        for (int b = 0; b < blocks; b++){
            tbl[b][0] = 0;
            for (int mask = 1; mask < 256; mask++)
                tbl[b][mask] = tbl[b][mask & (mask - 1)] + a[8 * b + __builtin_ctz(mask)];
        }

        for (int i = 0; i < n; i++){
            const unsigned char* p = reinterpret_cast<const unsigned char*>(&reach[i]);
            long long ans = 0;
            for (int b = 0; b < blocks; b++)
                ans += tbl[b][p[b]];
            cout << ans << " ";
        }
        cout << "\n";
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
