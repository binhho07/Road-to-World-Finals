// https://codeforces.com/gym/104333/problem/I

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 7;
int ans[maxn];

struct SOLVE{
    int n, q;
    void solve(){
        cin >> n;
        cout << ans[n] << "\n";
    }
};

vector<int> getDivisors(vector<pair<int, int>>& a) {
    vector<int> d = {1};

    for (auto [p, e] : a) {
        int sz = d.size();
        int pw = 1;

        for (int i = 1; i <= e; i++) {
            pw *= p;
            for (int j = 0; j < sz; j++) {
                d.push_back(d[j] * pw);
            }
        }
    }

    return d;
}

void precompute(){
    for (int i = 1; i <= 1e5; i++){
        int x = i;
        vector<pair<int, int>> fact;
        for (int j = 2; j * j <= x; j++){
            if (x % j == 0){
                fact.emplace_back(j, 0);
                while (x % j == 0){
                    x /= j;
                    fact.back().second += 2;
                }
            }
        }
        if (x > 1){
            fact.emplace_back(x, 2);
        }
        ans[i] = ans[i - 1];
        vector<int> d = getDivisors(fact);
        x = i * i;
        for (int y : d){
            int a = i, p = y, q = x / y;
            if (p > q) continue;
            int b = (q - p) / 2, c = (q + p) / 2;
            ans[i] += (a < b && b < c && (a * a + b * b == c * c));
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    precompute();
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
