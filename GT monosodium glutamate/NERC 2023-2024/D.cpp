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


void solve() {
    int b, n;
    cin >> b >> n;

    int ans_k = 0;
    int ans_t = 0;

    int curr = 1;

    for (int k = 1; k <= n; k++) {
        curr = (curr * b) % n;
        if (curr == 0) {
            ans_k = k;
            ans_t = 1;
            break;
        } else if (curr == 1) {
            ans_k = k;
            ans_t = 2;
            break;
        } else if (curr == n - 1) {
            ans_k = k;
            ans_t = 3;
            break;
        }
    }

    if (ans_k != 0) {
        cout << ans_t << " ";
    }

    cout << ans_k << endl;
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
