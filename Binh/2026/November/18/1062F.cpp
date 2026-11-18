// https://codeforces.com/contest/1062/problem/F

#include<bits/stdc++.h>
#define ii pair<int, int>

using namespace std;
const int maxn = 3e5 + 5;

struct SOLVE{
    int n, m;
    vector<vector<int>> adj, radj;

    vector<int> getOut(const vector<vector<int>>& adj){
        vector<int> deg(n + 1, 0), out(n + 1, -1e9);
        vector<int> q;
        for (int i = 1; i <= n; i++){
            for (int v : adj[i])
                deg[v]++;
        }

        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.emplace_back(i);
        int cnt = 0; 
        for (int i = 0; i < q.size(); i++){
            int u = q[i];
            int sz = (int)q.size() - i;
            int rem = n - (int)q.size();
            if (sz == 1){
                out[u] = rem;
            }
            else if (sz == 2) {
                bool found = false;
                for (int j : adj[q[i + 1]]){
                    if (deg[j] == 1){
                        found = true;
                    }
                }
                if (!found) out[u] = rem;
            }
            for (int i : adj[u])
                if (--deg[i] == 0){
                    q.emplace_back(i);
                }
        }
        return out;
    }

    void solve(){
        cin >> n >> m;
        adj = vector<vector<int>>(n + 1);
        radj = vector<vector<int>>(n + 1);
        for (int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            radj[v].emplace_back(u);
        }
        int ans = 0;
        auto out = getOut(adj);
        auto in = getOut(radj);
        for (int i = 1; i <= n; i++){
            if (out[i] + in[i] >= n - 2)
                ans++;        
        }
        cout << ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
