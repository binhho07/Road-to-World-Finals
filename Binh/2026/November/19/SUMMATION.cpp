// https://www.spoj.com/problems/SUMMATION/

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int mod = 100000007;

struct SOLVE{
    int n, m;
    void solve(int tc){
        cin >> n;
        int mul = 1;
        for (int i = 1; i < n; i++){
            mul = (mul * 2ll) % mod;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int x; cin >> x;
            ans = (ans + x * mul) % mod;
        }
        cout << "Case " << tc << ": " << ans << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1, cnt = 0;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve(++cnt);
    }
}
