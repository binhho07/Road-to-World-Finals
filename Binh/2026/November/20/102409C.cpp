// https://codeforces.com/problemset/gymProblem/102409/C

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;
    vector<vector<pair<int, int>>> adj;
    vector<int> a;
    vector<array<int, 2>> cur;

    void dfs(int x, int p, int anc, int bit){
        int v = a[x] >> bit & 1;
        cur[x][anc] = 1;
        cur[x][anc ^ 1] = 0;
        for (auto [i, j] : adj[x]) if (i != p){
            dfs(i, x, anc ^ (j >> bit & 1), bit);
            ans += (1 << bit) * cur[i][0] * cur[x][v ^ 1];
            ans += (1 << bit) * cur[i][1] * cur[x][v];
            cur[x][0] += cur[i][0];
            cur[x][1] += cur[i][1];
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        cur.resize(n + 1);        
        for (int i = 1; i < n; i++){
            int u, v, w; cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        for (int bit = 0; bit < 20; bit++)
            dfs(1, 1, 0, bit);
        cout << ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
