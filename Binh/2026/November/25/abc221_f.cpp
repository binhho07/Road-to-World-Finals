// https://atcoder.jp/contests/adt_hard_20240124_3/tasks/abc221_f

#include<bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 5e5 + 5, mod = 998244353;
int N;

struct SOLVE{
    int n, m, dia = 0, where, cnt = 0;
    vector<vector<int>> adj;
    vector<int> pre;
    vector<array<int, 2>> d;

    void init(){
        N = n;
        adj.resize(n + 1);
        d.resize(n + 1);
        pre.resize(n + 1);
    }

    void dfs(int x, int p, int h = 0){
        pre[x] = p;
        if (dia < h){
            dia = h;
            where = x;
        }
        for (int i : adj[x]) if (i != p){
            dfs(i, x, h + 1);
        }
    }

    void getDepth(int x, int p){
        d[x] = {0, 1};
        for (int i : adj[x]) if (i != p){
            getDepth(i, x);
            d[i][0]++;
            if (d[i][0] > d[x][0]){
                d[x] = d[i];
            } 
            else if (d[i][0] == d[x][0])
                d[x][1] += d[i][1];
        }
    }

    void solve(){
        cin >> n; 
        init();
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        if (n == 2) return cout << 1, void();
        dfs(1, 0);
        dia = 0;
        int from = where;
        dfs(from, 0);
        vector<int> diameter;
        while (where != from){
            diameter.emplace_back(where);
            where = pre[where];
        }
        diameter.emplace_back(from);
        int root = diameter[(int)diameter.size() / 2];
        getDepth(root, 0);
        vector<array<int, 2>> f;
        for (int i : adj[root]){
            f.emplace_back(d[i]);
        }
        sort(f.rbegin(), f.rend());
        int m1 = f[0][0], m2 = f[1][0];
        while (f.back()[0] != m2) f.pop_back();
        if (m1 != m2){
            int cnt = 0;
            for (int i = 1; i < f.size(); i++){
                cnt = (cnt + f[i][1]) % mod;
            }
            cout << (f[0][1] * cnt) % mod;
            return;
        }
        vector<int> dp(f.size() + 1), cnt(f.size() + 1);
        for (int i = 0; i < f.size(); i++){
            if (f[i][0] != m1) break;
            cnt[i + 1] = ((cnt[i] + 1) * (f[i][1] + 1) - 1 + mod) % mod;
            dp[i + 1] = (dp[i] + f[i][1] * cnt[i]) % mod;
        }
        cout << dp[f.size()];
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
    #endif  
    int T = 1; 
    //cin >> T;
    while (T--){
        SOLVE x;
        x.solve();
    }
}
