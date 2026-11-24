// https://codeforces.com/problemset/problem/1132/F

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 2>

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n;
    string s;

    int dp[505][505];
    vector<array<int, 26>> cnt;

    int f(int l, int r){
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int x = s[l - 1] - 'a';
        if (cnt[r][x] - cnt[l - 1][x] == r - l + 1) return dp[l][r] = 1;
        dp[l][r] = f(l + 1, r) + 1;
        for (int i = l + 1; i <= r; i++) if (s[i - 1] == s[l - 1])
            dp[l][r] = min(dp[l][r], f(l + 1, i - 1) + f(i, r));
        return dp[l][r];
    }

    void solve(){
        cin >> n >> s;
        cnt.resize(n + 1);
        memset(dp, -1, sizeof dp);
        for (int i = 1; i <= n; i++){
            cnt[i] = cnt[i - 1];
            cnt[i][s[i - 1] - 'a']++;
        }
        cout << f(1, n);
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
