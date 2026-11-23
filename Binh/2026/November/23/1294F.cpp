// https://codeforces.com/problemset/problem/1294/F

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 3>

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, ans = 0, root;

    vector<vector<int>> adj;
    vector<int> a;
    vector<int> dp;
    vector<pair<int, int>> f;

    ii merge(ii x, int y){
        vector<int> v = {x[0], x[1], x[2], y};
        sort(v.rbegin(), v.rend());
        x = {v[0], v[1], v[2]};
        return x;
    }

    int get(const ii& a){
        return a[0] + a[1] + a[2];
    }

    void dfs(int x = 1, int p = 0){
        vector<int> v;
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            dp[x] = max(dp[x], dp[i] + 1);
        }
    }

    void reroot(int x = 1, int p = 0, int fp = 0){
        vector<ii> pre = {{fp, 0, 0}}, suf = {{0, 0, 0}};
        for (int i : adj[x]) if (i != p){
            pre.emplace_back(merge(pre.back(), dp[i] + 1));
        }

        for (int i = (int)adj[x].size() - 1; i >= 0; i--){
            int j = adj[x][i];
            if (j == p) continue;
            suf.emplace_back(merge(suf.back(), dp[j] + 1));
        }

        reverse(suf.begin(), suf.end());
        if (ans < get(pre.back())){
            ans = get(pre.back());
            root = x;
        }

        int c = 0;
        for (int i : adj[x]) if (i != p){
            int cur = max(pre[c][0], suf[c + 1][0]) + 1;
            reroot(i, x, cur);
            c++;
        }
    }

    void getAns(int x, int p = 0){
        f[x] = {0, x};
        vector<pair<int, int>> v;
        for (int i : adj[x]) if (i != p){
            getAns(i, x);
            f[i].first++;
            f[x] = max(f[x], f[i]);
            if (p == 0) v.emplace_back(f[i]);
        }
        sort(v.rbegin(), v.rend());
        if (p == 0){
            vector<int> res;
            for (int i = 0; i < min(v.size(), (size_t)3); i++)
                res.emplace_back(v[i].second);
            if (res.size() < 3)
                res.emplace_back(root);
            if (res.size() < 3){
                for (int j = 1; j <= n; j++)
                    if (j != res[0] && j != res[1]){
                        res.emplace_back(j);
                        break;
                    }
            }
            for (int i : res) cout << i << " ";
        }
    }

    void solve(){
        cin >> n;
        adj.resize(n + 1);
        a.resize(n + 1);
        dp.resize(n + 1);
        f.resize(n + 1);
        for (int i = 2, u, v; i <= n; i++)
            cin >> u >> v,
            adj[u].emplace_back(v),
            adj[v].emplace_back(u);
        dfs();
        reroot();
        cout << ans << "\n";
        getAns(root);
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
