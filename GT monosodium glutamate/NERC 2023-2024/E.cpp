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

vector<int> vls;

vector<int> gt(int x) {
    vector<int> ans;

    for (int i = vls.size() - 1; i >= 0; i--) {
        while (x >= vls[i]) {
            x -= vls[i];
            ans.push_back(vls[i]);
        }
    }

    return ans;
}

string slv(int x, int y) {
    int k = (x + y) / 2;
    int d = x - k;

    string ans = "0";

    if (k != 0) {
        vector<int> curr = gt(abs(k));
        curr.push_back(0);

        for (auto it: curr) {
            if (k < 0) {
                ans += "-";
            } else {
                ans += "+";
            }
            ans += to_string(it);
        }
    }

    if (d != 0) {
        vector<int> curr = gt(d);
        for (auto it: curr) {
            ans += "+";
            ans += to_string(it);
            ans += "-";
            ans += "0";
        }
    }

    return ans;
}

void solve() {
    for (int c = 1; c <= 9; c++) {
        int curr = 0;
        for (int i = 0; i < 17; i++) {
            curr *= 10;
            curr += c;
            vls.push_back(curr);
        }
    }

    sort(all(vls));

    int x, y;
    cin >> x >> y;

    bool rev = false;

    if (x < y) {
        swap(x, y);
        rev = true;
    }

    string ans = "";

    if ((x - y) % 2 == 0) {
        ans = slv(x, y);
    } else {
        ans = slv(x - 11 * 12, y - 11 * 21);
    }

    if ((x - y) % 2 != 0) {
        ans = "11*12+" + ans;
    }

    if (rev) {
        reverse(all(ans));
    }

    cout << ans << endl;
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
