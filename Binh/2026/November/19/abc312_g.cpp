// https://atcoder.jp/contests/abc312/tasks/abc312_g

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
int cnt[maxn];
vector<int> adj[maxn];


struct SOLVE{
    int n, m, q, ans = 0;
    void dfs(int x, int p){
        cnt[x] = 1;
        int pf = 0;
        for (int i : adj[x]) if (i != p){
            dfs(i, x);
            ans += cnt[i] * pf;
            pf += cnt[i];
            cnt[x] += cnt[i];
        }
    }

    void dfs2(int x, int p, int tot){
        ans += (cnt[x] - 1) * tot;
        for (int i : adj[x]) if (i != p){
            dfs2(i, x, tot + cnt[x] - cnt[i]);
        }
    }

    void solve(){
        cin >> n;
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }       
        dfs(1, 1);
        dfs2(1, 1, 0); 
        ans = n * (n - 1) * (n - 2) / 6 - ans;
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
