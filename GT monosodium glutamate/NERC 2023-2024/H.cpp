#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1005;
int vis[maxn];
int n, m;
vector<int> nothing, adj[maxn], adj2[maxn];

vector<int> topo(vector<int> &v){
    vector<int> deg(n + 1, 0), order;
    for (int u : v) 
        for (int w : adj[u]) deg[w]++;
    for (int u : v) 
        if (deg[u] == 0) 
            order.push_back(u);
    for (int i = 0; i < order.size(); i++)
        for (int w : adj[order[i]]) 
            if (--deg[w] == 0) order.push_back(w);
    if (order.size() != v.size()) return nothing;
    return order;
}

vector<int> topo2(vector<int> &v, int cancel){
    vector<int> deg(n + 1, 0), order;
    for (int u : v) if (u != cancel)
        for (int w : adj[u]) if (w != cancel) deg[w]++;
    for (int u : v) 
        if (u != cancel && deg[u] == 0) 
            order.push_back(u);
    for (int i = 0; i < order.size(); i++)
        for (int w : adj[order[i]]) 
            if (w != cancel && --deg[w] == 0) order.push_back(w);
    if (order.size() != v.size() - 1) return nothing;
    return order;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj2[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++){
        if (vis[i] || adj2[i].empty()) continue;
        vector<int> v = {i};
        vis[i] = 1;
        for (int j = 0; j < v.size(); j++)
            for (int nxt : adj2[v[j]])
                if (!vis[nxt])
                    vis[nxt] = 1, v.emplace_back(nxt);
        auto to = topo(v);
        if (to.size()){
            for (int j = 0; j + 1 < to.size(); j++)
                ans.emplace_back(to[j], to[j + 1]);
            continue;
        }
        bool ok = false;
        for (int start : v){
            auto to = topo2(v, start);
            if (to.empty()) continue;
            ans.emplace_back(start, to[0]);
            for (int j = 0; j + 1 < to.size(); j++) ans.emplace_back(to[j], to[j + 1]);
            ans.emplace_back(to.back(), start);
            ok = true; 
            break;
        }
        if (!ok) return cout << "-1", 0;
    }
    cout << ans.size() << "\n";
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
}
