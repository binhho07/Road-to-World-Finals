// https://codeforces.com/problemset/problem/1324/F

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 2>

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n;
    string s;

    vector<vector<int>> adj;
    vector<int> a, dp, ans;


    void dfs(int x = 1, int p = 0){
        dp[x] = a[x] - (a[x] ^ 1);
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            dp[x] += max(0ll, dp[i]);
        }
    }

    void reroot(int x = 1, int p = 0, int fp = 0){
        vector<int> pre = {max(0ll, fp)}, suf = {0};
        for (int i : adj[x]) if (i != p){
            pre.emplace_back(pre.back() + max(0ll, dp[i]));
        }
        for (int i = (int)adj[x].size() - 1; i >= 0; i--){
            int j = adj[x][i];
            if (j == p) continue;
            suf.emplace_back(suf.back() + max(0ll, dp[j]));
        }
        reverse(suf.begin(), suf.end());
        ans[x] = pre.back() + a[x] - (a[x] ^ 1);
        int c = 0;
        for (int i : adj[x]) if (i != p){
            int cur = pre[c] + suf[c + 1] + a[x] - (a[x] ^ 1);
            reroot(i, x, cur);
            c++;
        }
    }

    void solve(){
        cin >> n;
        a.resize(n + 1);
        dp.resize(n + 1);
        adj.resize(n + 1);
        ans.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs();
        reroot();
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
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
