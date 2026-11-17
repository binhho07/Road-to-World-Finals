// https://codeforces.com/contest/2044/problem/G1

#include<bits/stdc++.h>
#define int long long  

using namespace std;
const int maxn = 2e5 + 5;

struct SOLVE{
    int n, m, cnt = 0;
    vector<int> pre, c, vis;
    vector<vector<int>> adj, radj;
    void dfs(int x, int p){
        if (c.size()) return;
        vis[x] = 1;
        pre[x] = p;
        for (int i : adj[x]){
            if (c.size()) return;
            if (vis[i] == 1){
                while (x != i){
                    c.emplace_back(x);
                    x = pre[x];
                }
                c.emplace_back(i);
                reverse(c.begin(), c.end());
                return;
            }
            if (vis[i] == 0) dfs(i, x);
        }
        vis[x] = 2;
    }

    void go(int x, int p, int c1, int cur = 0){
        vis[x] = 3;
        cur++;
        cnt = max(cnt, cur);
        for (int i : radj[x]) if (i != p && i != c1){
            go(i, x, c1, cur);
        }
    }

    void solve(){
        cin >> n;
        pre.resize(n + 1, 0);
        vis.resize(n + 1, 0);
        adj = vector<vector<int>>(n + 1, vector<int>());
        radj = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 1; i <= n; i++){
            int u = i, v; cin >> v;
            adj[u].emplace_back(v);
            radj[v].emplace_back(u);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) if (vis[i] == 0){
            c.clear();
            dfs(i, i);
            int cs = c.size();
            for (int j = 0; j < cs; j++){
                cnt = 0;
                int p = (j - 1 + cs) % cs;
                go(c[j], c[j], c[p]);
                ans = max(ans, cnt + 1);
            }
        }
        cout << ans << "\n";
    }
};





signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t; cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
