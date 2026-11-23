// https://codeforces.com/problemset/problem/1187/E

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, inf = 2e18;

struct SOLVE{
    int n, m, ans = 0;

    vector<vector<int>> adj;
    vector<int> a;
    vector<array<int, 2>> dp;

    array<int, 2> merge(array<int, 2> x, const array<int, 2>& y){
        x[0] += y[0];
        x[1] += y[1];
        return x;
    }

    void dfs(int x = 1, int p = 1){
        dp[x][0] = 1;
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            dp[x] = merge(dp[x], dp[i]);
        }
        dp[x][1] += dp[x][0];
    }

    void reroot(int x = 1, int p = 0, array<int, 2> fp = {0, 0}){
        vector<array<int, 2>> pre = {fp}, suf = {{0, 0}};
        for (int i : adj[x]) if (i != p){
            pre.emplace_back(merge(pre.back(), dp[i]));
        }
        for (int i = (int)adj[x].size() - 1; i >= 0; i--){
            int j = adj[x][i];
            if (j == p) continue;
            suf.emplace_back(merge(suf.back(), dp[j]));
        }
        reverse(suf.begin(), suf.end());
        ans = max(ans, pre.back()[1] + pre.back()[0] + 1);
        int c = 0;
        for (int i : adj[x]) if (i != p){
            array<int, 2> cur;
            cur[0] = pre[c][0] + suf[c + 1][0] + 1;
            cur[1] = pre[c][1] + suf[c + 1][1] + cur[0];
            reroot(i, x, cur);
            c++;
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        for (int i = 1, u, v; i < n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs();
        reroot();
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
