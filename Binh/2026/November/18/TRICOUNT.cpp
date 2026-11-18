// https://www.spoj.com/problems/TRICOUNT/

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 1e6 + 1;
int ans[maxn];
struct SOLVE{
    int n, m;
    void solve(){
        cin >> n;
        cout << ans[n] << "\n";
    }
};

void precompute(){
    ans[1] = 1;
    for (int i = 2; i < maxn; i++){
        ans[i] = ans[i - 1];
        ans[i] += i * (i + 1) / 2;
        ans[i] += (i + 1) * (i / 2);
        int h = i / 2;
        ans[i] -= h * (h + 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    precompute();
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
