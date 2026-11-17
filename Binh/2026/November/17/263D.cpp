// https://codeforces.com/contest/263/problem/D

#include<bits/stdc++.h>
#define int long long  

using namespace std;
const int maxn = 2e5 + 5;
int n, m, k;
int pre[maxn], vis[maxn];
vector<int> adj[maxn];


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    

    int s = 1;
    vector<int> path;
    vector<int> pos(n + 1, 0);

    while (true){
        path.emplace_back(s);
        pos[s] = path.size();
        bool found = false;
        for (int i : adj[s])
            if (!pos[i]){
                s = i;
                found = true;
                break;
            }
        if (found){
            continue;
        }
        int mn = s;
        for (int i : adj[s])
            if (pos[i] < pos[mn])
                mn = i;
        cout << path.size() - pos[mn] + 1 << "\n";
        for (int i = pos[mn] - 1; i < path.size(); i++)
            cout << path[i] << " ";
        return 0;
    }
}
