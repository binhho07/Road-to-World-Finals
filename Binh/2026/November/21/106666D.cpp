// https://codeforces.com/gym/106666/problem/D
 
#include<bits/stdc++.h>
#define int long long 
 
using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;
 
struct SOLVE{
    int n, m, q, ans = 0;
 
    void solve(){
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i++){
            ans = max(ans, a[i] * (n - i) - (a[n] - a[i]) * i);
        }
        cout << ans << "\n";
    }
};
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
