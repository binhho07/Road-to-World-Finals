// https://codeforces.com/gym/104333/problem/D

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 2e5 + 5, up = 500 * 500;
int dp[2][up * 3], a[maxn];

struct SOLVE{
    int n, m, q;
    string s;

    void solve(){
        cin >> n;
        int mx = 0, mn = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[i] > 0)
                mx += a[i];
            else mn += a[i];
        }
        int cu = 1, be = 0;
        dp[0][0 + up] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = -up; j <= up; j++)
                dp[cu][j + up] = dp[be][j + up];
            for (int j = -up; j <= up; j++) 
                if (dp[be][j + up]) dp[cu][j + a[i] + up] = 1;
            swap(be, cu);
        }
        int ans = 1e9;
        for (int i = -up; i <= up; i++){
            if (dp[be][i + up])
                ans = min(ans, abs(i * 2 - mx - mn));
        }
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
