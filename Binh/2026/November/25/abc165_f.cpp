// https://atcoder.jp/contests/abc165/tasks/abc165_f

#include<bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 5e5 + 5, INF = 1e18;
int N;

struct SOLVE{
    int n, m, dia = 0, where, cnt = 0;
    vector<vector<int>> adj;
    vector<int> a, nen, ans;
    vector<int> seg;
    vector<pair<int, int>> rollback;

    void init(){
        N = n;
        adj.resize(n + 1);
        seg.resize(4 * n + 5);
        a.resize(n + 1);
        ans.resize(n + 1);
    }

    void upd(int pos, int val, int id = 1, int l = 1, int r = N){
        if (l == r){
            rollback.emplace_back(id, seg[id]);
            seg[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) upd(pos, val, id * 2, l, mid);
        else upd(pos, val, id * 2 + 1, mid + 1, r);
        rollback.emplace_back(id, seg[id]);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }

    int get(int lx, int rx, int id = 1, int l = 1, int r = N){
        if (lx > r || l > rx) return 0;
        if (lx <= l && r <= rx) return seg[id];
        int mid = (l + r) / 2;
        return max(get(lx, rx, id * 2, l, mid), get(lx, rx, id * 2 + 1, mid + 1, r));
    }

    void dfs(int x = 1, int p = 1){
        int v = lower_bound(nen.begin(), nen.end(), a[x]) - nen.begin() + 1;
        int LIS = get(1, v - 1) + 1;
        int last = rollback.size();
        upd(v, LIS);
        ans[x] = get(1, N);
        for (int i : adj[x]) if (i != p)
            dfs(i, x);
        while (rollback.size() > last){
            auto [u, v] = rollback.back();
            rollback.pop_back();
            seg[u] = v;
        }
    }

    void solve(){
        cin >> n; 
        init();
        for (int i = 1; i <= n; i++)
            cin >> a[i],
            nen.emplace_back(a[i]);
        sort(nen.begin(), nen.end());
        nen.resize(unique(nen.begin(), nen.end()) - nen.begin());
        N = nen.size();
        for (int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        dfs();
        for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
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
