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
    int n;
    cin >> n;

    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<pair<int, int> > ans;

    for (int i = 0; i < n; i++) {
        int ind = -1;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                ind = j;
            }
        }

        vector<int> aft;

        for (int j = ind; j < n; j++) {
            if (a[j] > i) {
                aft.push_back(a[j]);
            }
        }

        for (auto it: aft) {
            ans.push_back({it, i});
        }

        reverse(all(aft));

        for (auto it: aft) {
            ans.push_back({i, it});
        }

        for (int j = ind; j >= 0; j--) {
            if (a[j] > i) {
                ans.push_back({i, a[j]});
            }
        }
    }

    cout << ans.size() << endl;

    reverse(all(ans));

    for (auto it: ans) {
        cout << it.ss + 1 << " " << it.ff + 1 << endl;
    }
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
    // cin >> t;

    while (t--) {
        solve();
    }
}
