// https://codeforces.com/gym/106666/problem/A

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, mod = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        vector<string> s(n);
        for (string& i : s)
            cin >> i,
            i[0] = 'G';
        cin >> m;
        for (int i = 1; i <= m; i++){
            string t; cin >> t;
            int found = 0;
            for (auto j : s)
                if (t == j)
                    found = 1;
            ans += found;
        }
        cout << ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
