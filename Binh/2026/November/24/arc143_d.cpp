// https://atcoder.jp/contests/arc143/tasks/arc143_d

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 2>

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, m, cnt;
    string res;

    vector<vector<tuple<int, int, int>>> adj;
    vector<array<int, 2>> a;
    vector<int> vis;


    set<pair<int, int>> ans;
 
    void dfs(int x = 1, int id = 0) {
        vis[x] = 1;
        for (auto [i, j, dir] : adj[x]) {
            if (j == id) continue;
            if (!vis[i]) dfs(i, j);
            if (res[j - 1] == '2') res[j - 1] = (char)(dir + '0');
        }
    }

    void solve(){
        cin >> n >> m;
        a.resize(m + 1);
        res.resize(m, '2');
        adj.resize(n + 1);
        vis.resize(n + 1);
        for (int i = 1; i <= m; i++) cin >> a[i][0];
        for (int i = 1; i <= m; i++){
            cin >> a[i][1];
            int u = a[i][0], v = a[i][1];
            adj[u].emplace_back(v, i, 0);
            adj[v].emplace_back(u, i, 1);
        }
        for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
        cout << res;
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
