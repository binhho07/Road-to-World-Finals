#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

vector<int> ops[4], g[N], ans;
int used[N], type[N];

void dfs(int v) {
    used[v] = 1;
    for (int i : g[v]) {
        if (used[i] == 1) {
            cout << -1 << '\n';
            exit(0);
        }
        if (!used[i]) {
            dfs(i);
        }
    }
    ans.push_back(v);
    used[v] = 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (a == "set" && b == "true") {
            ops[0].push_back(i);
            type[i] = 0;
        }
        else if (a == "unset" && b == "true") {
            ops[1].push_back(i);
            type[i] = 1;
        }
        else if (a == "set" && b == "false") {
            ops[2].push_back(i);
            type[i] = 2;
        }
        else {
            ops[3].push_back(i);
            type[i] = 3;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }
    if (ops[0].size() > 1 || ops[1].size() > 1) {
        cout << -1 << '\n';
        return 0;
    }
    if (!ops[0].empty()) {
        for (int i : ops[2]) {
            g[ops[0][0]].push_back(i);
        }
    }
    if (!ops[1].empty()) {
        for (int i : ops[2]) {
            g[i].push_back(ops[1][0]);
        }
    }
    if (!ops[0].empty() && !ops[1].empty()) {
        g[ops[0][0]].push_back(ops[1][0]);
    }
    if (!ops[0].empty()) {
        dfs(ops[0][0]);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    int x = 0;
    for (int i : ans) {
        if (type[i] == 0) {
            if (x == 1) {
                cout << -1 << '\n';
                return 0;
            }
            x = 1;
        }
        else if (type[i] == 1) {
            if (x == 0) {
                cout << -1 << '\n';
                return 0;
            }
            x = 0;
        }
        else if (type[i] == 2) {
            if (x == 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
        else {
            if (x == 1) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    for (int i : ans) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}
