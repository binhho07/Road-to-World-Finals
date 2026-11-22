// https://codeforces.com/gym/106666/problem/B

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        sort(a.begin(), a.end());
        for (int i = 0; i * 2 < a.size(); i++){
            ans += a[(int)a.size() - 1 - i] - a[i];
        }
        cout << ans;
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
