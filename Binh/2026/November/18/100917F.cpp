// https://codeforces.com/gym/100917/problem/F

#include<bits/stdc++.h>
#define int long long  
#define ii pair<int, int>

using namespace std;
const int maxn = 303, inf = 1e18;

struct SOLVE{
    int n, m;
    int a[maxn][maxn];
    void solve(){
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int s = 1; s <= n; s++){
            priority_queue<ii, vector<ii>, greater<>> pq;
            vector<int> branch(n + 1, 0);
            vector<int> par(n + 1, 0);
            pq.emplace(0, s);
            int dp[n + 1];
            for (int i = 1; i <= n; i++)
                dp[i] = inf;
            dp[s] = 0;
            int res = inf;
            while (pq.size()){
                auto [u, v] = pq.top();
                pq.pop();
                if (u != dp[v]) continue;
                for (int j = 1; j <= n; j++) if (a[v][j] > 0) {
                    if (dp[j] > u + a[v][j]){
                        pq.emplace(dp[j] = u + a[v][j], j);
                        par[j] = v;
                        branch[j] = (v == s ? j : branch[v]);
                    }
                }
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (a[i][j] > 0 && branch[i] != branch[j] 
                        && par[i] != j && par[j] != i) 
                        res = min(res, dp[i] + a[i][j] + dp[j]);            
            cout << (res == inf ? -1 : res) << "\n";
        }
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1; 
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
