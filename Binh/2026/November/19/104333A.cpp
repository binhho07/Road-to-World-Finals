// https://codeforces.com/gym/104333/problem/A

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
int p[maxn], sq[maxn];

struct SOLVE{
    int n, q;
    void solve(){
        cin >> n;
        vector<int> a(n), b(n);
        vector<array<int, 2>> cnt(17);
        for (int x : a){
            cin >> x;
            for (int i = 0; i < 17; i++){
                cnt[i][x >> i & 1]++;
            }
        }
        int perm = 1;
        for (int i = 1; i < n; i++)
            perm = (perm * i) % mod;
        int ans = 0;
        for (int x : b){
            cin >> x;
            for (int i = 0; i < 17; i++){
                int st = (x >> i & 1) ^ 1;
                ans = (ans + cnt[i][st] * perm % mod * (1ll << i)) % mod;
            }
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
