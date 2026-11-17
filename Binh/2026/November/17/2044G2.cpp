// https://codeforces.com/contest/2044/problem/G2

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

    void go(int x, int p){
        vis[x] = 3;
        cnt++;
        for (int i : radj[x]) if (i != p){
            go(i, x);
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
                for (int nxt : radj[c[j]]) if (nxt != c[p]) {
                    cnt = 0;
                    go(nxt, nxt);
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans + 2 << "\n";
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
