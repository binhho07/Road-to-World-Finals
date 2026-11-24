// https://codeforces.com/contest/2260/problem/E

#include<bits/stdc++.h>
#define int long long 
#define ii array<int, 4>

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, m;
    string s;

    vector<ii> cnt;

    ii get(int l, int r){
        ii x;
        for (int i = 0; i < 4; i++)
            x[i] = cnt[r][i] - cnt[l - 1][i];
        return x;
    }

    int div(int x, int y){
        if (x <= 0) return 0;
        return (x - 1) / y + 1;
    }

    int calc(int a, int b, int c){
        int A = a - b, C = c - b;
        int s = max({div(A, 2), div(C, 2), div(A + C, 3)});  
        return 2 * b - a - c + 4 * s;
    }
 
    void solve(){
        cin >> n >> m >> s;
        cnt.resize(n + 1);
        for (int i = 1; i <= n; i++){
            cnt[i] = cnt[i - 1];
            if (i > 1){
                int cur = (s[i - 2] - '0') + (s[i - 1] - '0') * 2;
                cnt[i][cur]++;
            }
        }
        for (int i = 1; i <= m; i++){
            int l, r; cin >> l >> r;
            if (r - l + 1 <= 2) {
                cout << 4 - (r - l + 1) << "\n";
                continue;
            }
            ii x = get(l + 1, r);
            int cur = (s[r - 1] - '0') + (s[l - 1] - '0') * 2;
            x[cur]++;
            cout << calc(x[0], x[1], x[3]) << "\n";
        }
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
