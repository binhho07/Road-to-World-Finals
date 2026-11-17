#include <bits/stdc++.h>
#define int long long 
#define iii array<int, 3>

using namespace std;
int x, k;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);

    cin >> x >> k;
    vector<vector<pair<int, int>>> blocks(k);   
    for (int i = 0; i < k; i++) {
        int l, s = 0; cin >> l;
        int sum = 0, need = 0;
        for (int j = 0; j < l; j++) {
            int v; cin >> v;
            s += v;
            need = max(need, -s);
            if (s > 0) {
                blocks[i].emplace_back(need, s);
                s = 0; need = 0;
            }
        }
    }

    priority_queue<iii, vector<iii>, greater<>> pq;

    for (int i = 0; i < k; i++)
        if (!blocks[i].empty()) pq.push(iii{blocks[i][0].first, i, 0});

    while (!pq.empty()) {
        auto [need, i, j] = pq.top();
        if (need > x) break;
        pq.pop();
        x += blocks[i][j].second;
        if (j + 1 < (int)blocks[i].size())
            pq.push({blocks[i][j + 1].first, i, j + 1});
    }
    cout << x;
}
