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

vector<int> bit_block(int bit, int x) {
    int offset = bit * 32 * 16;
    int word_offset = bit * 32;

    vector<int> ans;

    ans.push_back(((1 << 16) - 16) | bit);
    ans.push_back(offset + 5 * 16 + 3);
    ans.push_back(word_offset + 3);
    ans.push_back((1ll << 14));
    ans.push_back((1ll << 14));
    ans.push_back(word_offset + 16 + 4 * (int) ((x >> bit) & 1));
    for (int i = 0; i < 10; i++) {
        ans.push_back(0);
    }

    int zero = offset + 3 * 16;
    int one = offset + 3 * 16 + 14;

    int io_last = (1ll << 16) - 16;
    int io_last_word = (1ll << 12) - 1;

    int next_begin = io_last_word;

    if (bit != 15) {
        next_begin = word_offset + 32;
    }

    ans.push_back(one);
    ans.push_back(io_last);
    ans.push_back(next_begin);
    ans.push_back(0);

    ans.push_back(zero);
    ans.push_back(io_last);
    ans.push_back(io_last_word);
    ans.push_back(0);

    ans.push_back(zero);
    ans.push_back(io_last);
    ans.push_back(io_last_word);
    ans.push_back(0);

    ans.push_back(one);
    ans.push_back(io_last);
    ans.push_back(next_begin);
    ans.push_back(0);

    return ans;
}

string word(int x) {
    vector<int> spl;
    for (int i = 0; i < 4; i++) {
        spl.push_back(x % 16);
        x /= 16;
    }
    reverse(all(spl));
    string ans = "";
    for (auto it: spl) {
        if (it < 10) {
            ans += ('0' + it);
        } else {
            ans += ('a' + (it - 10));
        }
    }
    return ans;
}

void solve() {
    int x;
    cin >> x;

    vector<int> ans;

    for (int bit = 0; bit < 16; bit++) {
        vector<int> curr = bit_block(bit, x);
        for (auto it: curr) {
            ans.push_back(it);
        }
    }

    for (auto it: ans) {
        cout << word(it) << " ";
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
