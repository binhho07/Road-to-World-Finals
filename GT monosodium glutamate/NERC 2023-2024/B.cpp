#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using ll = long long;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define ordered_set tree < int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update >
// #define double long double
#define endl "\n"

const ll INF = 1e18;

const int MOD = 998244353;

int binpow(int x, int pw) {
    if (pw == 0) {
        return 1;
    }
    if (pw % 2 == 1) {
        return binpow(x, pw - 1) * x % MOD;
    }
    int hlf = binpow(x, pw / 2);
    return (hlf * hlf) % MOD;
}

int rev(int x) {
    return binpow(x, MOD - 2);
}

int gsum(int x) {
    return x * (x + 1) / 2;
}

int gvl(int x) {
    if (x == 1) {
        return 0;
    }
    if (x == 2) {
        return 0;
    }
    int f = (x - 1) / 2;
    int s = (x - 2) / 2;
    return gsum(f) + gsum(s);
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> fact(2 * k + 1, 1);

    for (int i = 1; i <= 2 * k; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    auto cnk = [&](int cnk_n, int cnk_k) {
        return fact[cnk_n] * rev(fact[cnk_k] * fact[cnk_n - cnk_k] % MOD) % MOD;
    };

    int small = n / k;
    int big = n / k + 1;

    int big_c = n % k;
    int small_c = k - big_c;

    int ans = small_c * gvl(small) + big_c * gvl(big);

    cout << ans << " ";

    if (small > 3) {
        int lo = (small % 2 == 0) ? small : small - 1;
        int rem = n - k * lo;

        auto mul = [&](int a, int b, int c) -> int {
            if (a < 0 || b < 0 || c < 0) {
                return 0;
            }
            return cnk(a + b + c, a) * cnk(b + c, b) % MOD;
        };

        int cnt = 0;

        for (int z = 0; 2 * z <= rem; z++) {
            int y = rem - 2 * z;
            int x = k - y - z;
            if (x < 0) {
                continue;
            }
            cnt += mul(x - 1, y, z) + 2 * mul(x, y - 1, z) + mul(x, y, z - 1);
            cnt %= MOD;
        }

        cout << cnt << endl;
        return;
    }

    if (small == 1) {
        cout << cnk(k - 1, n - (k + 1)) << endl;
        return;
    }

    int need = n - 2 * k;

    int cnt = 0;

    for (int t = 0; 2 * t <= need && t <= k - 1; t++) {
        if (2 * t + k + 1 - t >= need) {
            cnt += cnk(k - 1, t) * cnk(k + 1 - t, need - 2 * t);
            cnt %= MOD;
        }
    }

    cout << cnt << endl;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
