// https://codeforces.com/contest/1454/problem/E

#include<bits/stdc++.h>
#define int long long  

using namespace std;
const int maxn = 2e5 + 5;

struct SOLVE{
    int n, m, cnt = 0;
    vector<int> pre, c;
    vector<vector<int>> adj;
    void dfs(int x, int p){
        if (c.size()) return;
        pre[x] = p;
        for (int i : adj[x]) if (i != p){
            if (c.size()) return;
            if (pre[i]){
                while (x != i){
                    c.emplace_back(x);
                    x = pre[x];
                }
                c.emplace_back(i);
                return;
            }
            dfs(i, x);
        }
    }

    void go(int x, int p, int c1, int c2){
        cnt++;
        for (int i : adj[x]) if (i != p && i != c1 && i != c2){
            go(i, x, c1, c2);
        }
    }

    void solve(){
        cin >> n;
        pre.resize(n + 1, 0);
        adj = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 0; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs(1, 1);
        int ans = n * (n - 1);
        int cs = c.size();
        for (int i = 0; i < cs; i++){
            int p = (i - 1 + cs) % cs;
            int s = (i + 1) % cs;
            cnt = 0;
            go(c[i], c[i], c[p], c[s]);
            ans -= cnt * (cnt - 1) / 2;
        }
        cout << ans << "\n";
    }
};





signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t; cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
