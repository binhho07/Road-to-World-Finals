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

const int MOD = 1000'000'000 + 7;


void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int> > a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].ss;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i].ff;
    }

    sort(all(a));

    vector<int> lens = {0};

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        lens.push_back(lens.back() + x);
    }

    vector<int> bk;
    int curr = INF;

    for (int i = n - 1; i >= 0; i--) {
        curr = min(curr, a[i].ff);
        bk.push_back(curr);
        curr -= a[i].ss;
    }

    reverse(all(bk));

    vector<int> pref = {0};

    for (auto it: a) {
        pref.push_back(pref.back() + it.ss);
    }

    while (q--) {
        int t;
        cin >> t;

        int ind = upper_bound(all(bk), t) - bk.begin();

        int num = n - (bk.size() - ind);
        int grn = t;

        if (ind < n) {
            grn = min(grn, bk[ind] - a[ind].ss);
        }

        grn -= pref[num];

        int ans = upper_bound(all(lens), grn) - lens.begin() - 1;

        cout << ans << " ";
    }

    cout << endl;
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
