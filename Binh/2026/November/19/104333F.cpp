// https://codeforces.com/gym/104333/problem/F

#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7;
int a[maxn], par[maxn], mark[maxn];
multiset<int> s[maxn];
array<int, 2> edges[maxn];
array<int, 3> qr[maxn];

struct SOLVE{
    int n, m, q;

    int fp(int x){
        return par[x] < 0 ? x : par[x] = fp(par[x]);
    }

    void unite(int u, int v){
        if ((u = fp(u)) == (v = fp(v))) return;
        if (s[u].size() < s[v].size()) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        for (int i :s[v])
            s[u].emplace(i);
    }

    void solve(){
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++){
            cin >> edges[i][0] >> edges[i][1];
        }
        cin >> q;
        for (int i = 1; i <= q; i++){
            cin >> qr[i][0] >> qr[i][1];
            if (qr[i][0] == 1){
                mark[qr[i][1]] = 1;
            }
            else if (qr[i][0] == 2){
                cin >> qr[i][2];
                swap(qr[i][2], a[qr[i][1]]);
            }
        }  
        for (int i = 1; i <= n; i++)
            s[i].emplace(a[i]);
        memset(par, -1, sizeof par);
        for (int i = 1; i <= m; i++)
            if (!mark[i])
                unite(edges[i][0], edges[i][1]);
        vector<int> ans;
        for (int i = q; i >= 1; i--){
            if (qr[i][0] == 1){
                int id = qr[i][1];
                unite(edges[id][0], edges[id][1]);
            } else if (qr[i][0] == 2){
                int v = a[qr[i][1]];
                int u = fp(qr[i][1]);
                auto it = s[u].find(v);
                s[u].erase(it);
                s[u].emplace(qr[i][2]);
                a[qr[i][1]] = qr[i][2];
            }
            else{
                ans.emplace_back(*s[fp(qr[i][1])].rbegin());
            }
        }
        reverse(ans.begin(), ans.end());
        for (int i : ans) cout << i << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
