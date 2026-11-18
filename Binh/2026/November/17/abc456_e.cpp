// https://atcoder.jp/contests/abc456/tasks/abc456_e

#include<bits/stdc++.h>
#define int long long  

using namespace std;
const int maxn = 2e5 + 5;

struct SOLVE{
    int n, m, W, found = 0;
    vector<int> vis[10];
    vector<vector<int>> adj;
    vector<string> s;
    void dfs(int x, int state){
        vis[state][x] = 1;
        for (int i : adj[x]) if (s[i][(state + 1) % W] == 'o') {
            if (vis[(state + 1) % W][i]  == 1){
                found = 1;
            } else if (vis[(state + 1) % W][i] == 0) {
                dfs(i, (state + 1) % W);
            }
        }
        vis[state][x] = 2;
    }

    void solve(){
        cin >> n >> m;
        adj = vector<vector<int>>(n + 1, vector<int>());
        s.resize(n + 1);
        for (int i = 0; i < 10; i++)
            vis[i].resize(n + 1, 0);
        for (int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        cin >> W;
        for (int i = 1; i <= n; i++){
            cin >> s[i];
            adj[i].emplace_back(i);
        }
 
        for (int i = 1; i <= n; i++){
            if (!vis[0][i] && s[i][0] == 'o')
                dfs(i, 0);
        }

        cout << (found ? "YES\n" : "NO\n");
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
